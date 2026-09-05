/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body for Flame Sensor, Buzzer & ThingsBoard
  *                    (STM32 + WE10 WiFi/MQTT module)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>

/* Buzzer */
#define BUZZER_PORT      GPIOB
#define BUZZER_PIN       GPIO_PIN_0

/* Flame sensor (analog, PA0 / ADC1 Channel 0) */
/* NOTE: this sensor's ADC reading DROPS as IR/flame intensity rises, so
   "detected" means flame_adc < FLAME_THRESHOLD, not >. 2000 is a rough
   starting point for a 12-bit ADC (0-4095) — watch the printed flame_adc
   values with no flame vs. a real flame nearby and set this roughly
   halfway between the two before relying on it. */
#define FLAME_THRESHOLD  2000

/* ThingsBoard Settings */
#define TB_HOST          "thingsboard.cloud"
#define TB_PORT          "1883"
#define TB_ACCESS_TOKEN  "6K5lSP9qHRWvs3xtHzD7"     /* Paste your ThingsBoard device Access Token here. */
                                 /* NEVER commit a real token to source control -    */
                                 /* keep it in a separate untracked secrets.h if     */
                                 /* this project goes into git.                      */

/* WiFi credentials for WE10 module */
#define WIFI_SSID        "Hero"
#define WIFI_PASSWORD    "hero1234"

/* Response read tuning */
#define WE10_RESP_BUF_LEN      160
#define WE10_RESP_TIMEOUT_MS   2000   /* max total time to wait for a response  */
#define WE10_BYTE_TIMEOUT_MS   50     /* per-byte poll; also used as "idle gap" */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

UART_HandleTypeDef huart1;   /* WE10 module (AT commands)   */
UART_HandleTypeDef huart2;   /* Debug console (ST-Link VCP) */

/* USER CODE BEGIN PV */
uint32_t flame_adc = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART1_UART_Init(void);

/* USER CODE BEGIN PFP */
static uint16_t WE10_ReadResponse(char *buffer, uint16_t max_len, uint32_t timeout_ms);
static uint8_t  WE10_SendCmd(const char *cmd, char *resp_out, uint16_t resp_out_len);
uint8_t  WE10_Init(const char *ssid, const char *password);
uint8_t  MQTT_Init(void);
void     mqtt_publish_data(uint8_t detected);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* Retarget printf() to UART2 (ST-Link debug console) */
int __io_putchar(int ch)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}

/**
  * @brief  Read a variable-length AT response from UART1 without blocking
  *         for a fixed byte count. Keeps reading one byte at a time and
  *         resets the timeout clock every time a new byte arrives, so it
  *         returns as soon as the module goes quiet (or the overall
  *         timeout expires if nothing ever arrives).
  * @retval Number of bytes read into buffer (0 = nothing received at all).
  */
static uint16_t WE10_ReadResponse(char *buffer, uint16_t max_len, uint32_t timeout_ms)
{
    uint16_t idx = 0;
    uint32_t start = HAL_GetTick();
    uint8_t byte;

    memset(buffer, 0, max_len);

    while ((HAL_GetTick() - start) < timeout_ms && idx < (max_len - 1))
    {
        if (HAL_UART_Receive(&huart1, &byte, 1, WE10_BYTE_TIMEOUT_MS) == HAL_OK)
        {
            buffer[idx++] = (char)byte;
            start = HAL_GetTick();   /* reset "quiet gap" timer on each byte */
        }
        /* else: no byte this poll, keep looping until overall timeout */
    }

    buffer[idx] = '\0';
    return idx;
}

/**
  * @brief  Send an AT-style command to the WE10 module over UART1, print
  *         the command and response over the debug console (UART2), and
  *         optionally hand the raw response back to the caller.
  * @retval 1 if the response contained "OK", 0 otherwise (timeout / ERROR).
  */
static uint8_t WE10_SendCmd(const char *cmd, char *resp_out, uint16_t resp_out_len)
{
    char buffer[WE10_RESP_BUF_LEN];
    uint16_t len;

    HAL_UART_Transmit(&huart1, (uint8_t *)cmd, strlen(cmd), 1000);
    len = WE10_ReadResponse(buffer, sizeof(buffer), WE10_RESP_TIMEOUT_MS);

    printf("CMD : %s", cmd);
    if (len > 0)
    {
        printf("RESP: %s\r\n", buffer);
    }
    else
    {
        printf("RESP: (timeout / no response)\r\n");
    }

    if (resp_out != NULL && resp_out_len > 0)
    {
        strncpy(resp_out, buffer, resp_out_len - 1);
        resp_out[resp_out_len - 1] = '\0';
    }

    return (len > 0 && strstr(buffer, "OK") != NULL) ? 1 : 0;
}

/**
  * @brief  Reset the WE10 module and connect it to the given WiFi network.
  * @retval 1 if every step in the sequence responded with OK, 0 if any
  *         step failed or timed out (check the debug console for which).
  */
uint8_t WE10_Init(const char *ssid, const char *password)
{
    char cmd[128];
    char resp[WE10_RESP_BUF_LEN];
    uint8_t ok = 1;

    ok &= WE10_SendCmd("CMD+RESET\r\n", resp, sizeof(resp));
    HAL_Delay(3000);

    ok &= WE10_SendCmd("CMD+WIFIMODE=1\r\n", resp, sizeof(resp));   /* Station mode */
    HAL_Delay(1000);

    snprintf(cmd, sizeof(cmd), "CMD+CONTOAP=%s,%s\r\n", ssid, password);
    ok &= WE10_SendCmd(cmd, resp, sizeof(resp));
    HAL_Delay(4000);

    /* Status query response format is module-specific; this just logs it. */
    WE10_SendCmd("CMD?WIFI\r\n", resp, sizeof(resp));
    HAL_Delay(1000);

    if (!ok)
    {
        printf(">>> WiFi init: one or more AT commands did NOT return OK. "
               "Check wiring/baud rate and the exact AT command syntax "
               "in the WE10 datasheet.\r\n");
    }

    return ok;
}

/**
  * @brief  Configure and start an MQTT session from the WE10 module to
  *         ThingsBoard Cloud. ThingsBoard authenticates MQTT clients using
  *         the device Access Token as the MQTT username (no password).
  * @retval 1 if every step responded with OK, 0 otherwise.
  */
uint8_t MQTT_Init(void)
{
    char cmd[160];
    char resp[WE10_RESP_BUF_LEN];
    uint8_t ok = 1;

    /* Set broker host + port */
    snprintf(cmd, sizeof(cmd), "CMD+MQTTNETCFG=%s,%s\r\n", TB_HOST, TB_PORT);
    ok &= WE10_SendCmd(cmd, resp, sizeof(resp));
    HAL_Delay(1000);

    /* Client ID, username = access token, password = blank.
       NOTE: double-check this field order/count against the WE10 AT
       command manual for CMD+MQTTCONCFG — module firmwares vary. */
    snprintf(cmd, sizeof(cmd), "CMD+MQTTCONCFG=3,FLAME_SENSOR,%s,,,,,,,,\r\n", TB_ACCESS_TOKEN);
    ok &= WE10_SendCmd(cmd, resp, sizeof(resp));
    HAL_Delay(1000);

    ok &= WE10_SendCmd("CMD+MQTTSTART=1\r\n", resp, sizeof(resp));
    HAL_Delay(3000);

    if (ok)
    {
        printf(">>> MQTT session appears to be up. Check the ThingsBoard "
               "device's 'Latest telemetry' tab for incoming data.\r\n");
    }
    else
    {
        printf(">>> MQTT init: one or more AT commands did NOT return OK. "
               "Verify TB_ACCESS_TOKEN and the MQTTCONCFG argument order.\r\n");
    }

    return ok;
}

/**
  * @brief  Publish current flame status as telemetry to ThingsBoard.
  */
void mqtt_publish_data(uint8_t detected)
{
    char payload[128];
    char cmd_buffer[256];
    char resp[WE10_RESP_BUF_LEN];

    printf("--------------------------------\r\n");
    printf("Flame ADC : %lu\r\n", flame_adc);

    if (detected)
    {
        printf("Status : Fire Detected! Buzzer ON\r\n");
        snprintf(payload, sizeof(payload),
                 "{\"flame_adc\":%lu,\"flame_detected\":true,\"status\":\"Fire Detected\"}",
                 flame_adc);
    }
    else
    {
        printf("Status : Safe (No Fire)\r\n");
        snprintf(payload, sizeof(payload),
                 "{\"flame_adc\":%lu,\"flame_detected\":false,\"status\":\"No Fire\"}",
                 flame_adc);
    }

    /* Wrap payload in quotes so the WE10 AT parser doesn't split on commas */
    snprintf(cmd_buffer, sizeof(cmd_buffer),
             "CMD+MQTTPUB=\"v1/devices/me/telemetry\",\"%s\"\r\n", payload);

    if (!WE10_SendCmd(cmd_buffer, resp, sizeof(resp)))
    {
        printf(">>> Publish may have failed (no OK from module). If this "
               "keeps happening, re-check MQTT_Init() succeeded.\r\n");
    }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();

  /* USER CODE BEGIN 2 */
  printf("\r\n--- Flame Sensor + ThingsBoard (STM32 + WE10) ---\r\n");

  /* Connect WE10 module to WiFi */
  uint8_t wifi_ok = WE10_Init(WIFI_SSID, WIFI_PASSWORD);

  /* Connect to ThingsBoard Cloud via MQTT */
  uint8_t mqtt_ok = 0;
  if (wifi_ok)
  {
      mqtt_ok = MQTT_Init();
  }
  else
  {
      printf(">>> Skipping MQTT_Init() because WiFi did not connect. "
             "Fix WiFi first, then telemetry will start flowing.\r\n");
  }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    /* Read flame sensor analog value (PA0 / ADC1 Channel 0) */
    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK)
    {
        flame_adc = HAL_ADC_GetValue(&hadc1);
    }
    HAL_ADC_Stop(&hadc1);

    /* Flame detection logic: this sensor's analog output DROPS as IR/flame
       intensity rises (phototransistor conducts harder -> lower voltage),
       so a strong flame gives a LOW ADC reading and weak ambient light
       gives a HIGH one. Detect when the reading falls BELOW the threshold. */
    uint8_t detected = (flame_adc < FLAME_THRESHOLD) ? 1 : 0;

    if (detected)
    {
        /* Buzzer + onboard LED ON */
        HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
    }
    else
    {
        /* Buzzer + onboard LED OFF */
        HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
    }

    /* Only attempt to publish if MQTT actually came up; otherwise this
       will just spam timeouts to the debug console every 2 seconds. */
    if (mqtt_ok)
    {
        mqtt_publish_data(detected);
    }
    else
    {
        printf("--------------------------------\r\n");
        printf("Flame ADC : %lu (MQTT not connected, not publishing)\r\n", flame_adc);
    }

    HAL_Delay(2000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{
  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data
  * Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding
  * rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */
}

/**
  * @brief USART1 Initialization Function (WE10 module)
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{
  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 38400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */
}

/**
  * @brief USART2 Initialization Function (Debug console)
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{
  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PB0 (Buzzer Pin) */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
