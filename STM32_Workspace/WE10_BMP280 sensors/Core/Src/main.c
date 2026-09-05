
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include <stdlib.h>
#include <math.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* ---------------- BMP280 types ---------------- */
typedef struct {
    uint16_t dig_T1;
    int16_t  dig_T2;
    int16_t  dig_T3;

    uint16_t dig_P1;
    int16_t  dig_P2;
    int16_t  dig_P3;
    int16_t  dig_P4;
    int16_t  dig_P5;
    int16_t  dig_P6;
    int16_t  dig_P7;
    int16_t  dig_P8;
    int16_t  dig_P9;
} BMP280_Calib;

typedef struct {
    float temperature; /* deg C */
    float pressure;    /* hPa */
    float altitude;    /* meters, estimated from pressure */
} BMP280_Data;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* ---------------- BMP280 defines ---------------- */
/* 7-bit I2C address is 0x76 (SDO -> GND) or 0x77 (SDO -> VDDIO).
 * HAL_I2C functions want the 8-bit (already shifted) address. */
#define BMP280_I2C_ADDR   (0x76 << 1)

#define BMP280_REG_ID          0xD0
#define BMP280_REG_RESET       0xE0
#define BMP280_REG_STATUS      0xF3
#define BMP280_REG_CTRL_MEAS   0xF4
#define BMP280_REG_CONFIG      0xF5
#define BMP280_REG_PRESS_MSB   0xF7
#define BMP280_REG_CALIB_START 0x88   /* 24 bytes: dig_T1..dig_P9 */

#define BMP280_CHIP_ID         0x58

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
static BMP280_Calib calib;
static int32_t t_fine; /* shared between temp and pressure compensation, per datasheet */
BMP280_Data bmp280_data;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* BMP280 driver */
static HAL_StatusTypeDef BMP280_ReadReg(I2C_HandleTypeDef *hi2c, uint8_t reg, uint8_t *buf, uint16_t len);
static HAL_StatusTypeDef BMP280_WriteReg(I2C_HandleTypeDef *hi2c, uint8_t reg, uint8_t value);
static void BMP280_ReadCalibration(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef BMP280_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef BMP280_ReadData(I2C_HandleTypeDef *hi2c, BMP280_Data *data);
static float BMP280_CompensateTemperature(int32_t adc_T);
static float BMP280_CompensatePressure(int32_t adc_P);

/* WE10 WiFi / MQTT driver */
void WE10_Init(char *SSID, char *PASSWD);
void MQTT_Init(void);
void mqtt_publish_bmp280(float temperature, float pressure, float altitude);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* =========================================================================
 *                              BMP280 DRIVER
 * ========================================================================= */

static HAL_StatusTypeDef BMP280_ReadReg(I2C_HandleTypeDef *hi2c, uint8_t reg, uint8_t *buf, uint16_t len)
{
    return HAL_I2C_Mem_Read(hi2c, BMP280_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, buf, len, 100);
}

static HAL_StatusTypeDef BMP280_WriteReg(I2C_HandleTypeDef *hi2c, uint8_t reg, uint8_t value)
{
    return HAL_I2C_Mem_Write(hi2c, BMP280_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &value, 1, 100);
}

static void BMP280_ReadCalibration(I2C_HandleTypeDef *hi2c)
{
    uint8_t buf[24];
    BMP280_ReadReg(hi2c, BMP280_REG_CALIB_START, buf, 24);

    calib.dig_T1 = (uint16_t)(buf[1]  << 8 | buf[0]);
    calib.dig_T2 = (int16_t)(buf[3]  << 8 | buf[2]);
    calib.dig_T3 = (int16_t)(buf[5]  << 8 | buf[4]);

    calib.dig_P1 = (uint16_t)(buf[7]  << 8 | buf[6]);
    calib.dig_P2 = (int16_t)(buf[9]  << 8 | buf[8]);
    calib.dig_P3 = (int16_t)(buf[11] << 8 | buf[10]);
    calib.dig_P4 = (int16_t)(buf[13] << 8 | buf[12]);
    calib.dig_P5 = (int16_t)(buf[15] << 8 | buf[14]);
    calib.dig_P6 = (int16_t)(buf[17] << 8 | buf[16]);
    calib.dig_P7 = (int16_t)(buf[19] << 8 | buf[18]);
    calib.dig_P8 = (int16_t)(buf[21] << 8 | buf[20]);
    calib.dig_P9 = (int16_t)(buf[23] << 8 | buf[22]);
}

HAL_StatusTypeDef BMP280_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t id = 0;

    if (BMP280_ReadReg(hi2c, BMP280_REG_ID, &id, 1) != HAL_OK)
        return HAL_ERROR;

    if (id != BMP280_CHIP_ID)
        return HAL_ERROR;

    /* Soft reset */
    BMP280_WriteReg(hi2c, BMP280_REG_RESET, 0xB6);
    HAL_Delay(10);

    BMP280_ReadCalibration(hi2c);

    /* config: standby 62.5ms, filter off */
    BMP280_WriteReg(hi2c, BMP280_REG_CONFIG, 0x00);

    /* ctrl_meas: osrs_t=1, osrs_p=1, mode=normal (0b00100111 = 0x27) */
    BMP280_WriteReg(hi2c, BMP280_REG_CTRL_MEAS, 0x27);
    HAL_Delay(10);

    return HAL_OK;
}

/* Bosch reference compensation formulas (floating point variant) */
static float BMP280_CompensateTemperature(int32_t adc_T)
{
    float var1, var2, T;

    var1 = (((float)adc_T) / 16384.0f - ((float)calib.dig_T1) / 1024.0f) * ((float)calib.dig_T2);
    var2 = ((((float)adc_T) / 131072.0f - ((float)calib.dig_T1) / 8192.0f) *
            (((float)adc_T) / 131072.0f - ((float)calib.dig_T1) / 8192.0f)) * ((float)calib.dig_T3);

    t_fine = (int32_t)(var1 + var2);
    T = (var1 + var2) / 5120.0f;
    return T;
}

static float BMP280_CompensatePressure(int32_t adc_P)
{
    float var1, var2, p;

    var1 = ((float)t_fine / 2.0f) - 64000.0f;
    var2 = var1 * var1 * ((float)calib.dig_P6) / 32768.0f;
    var2 = var2 + var1 * ((float)calib.dig_P5) * 2.0f;
    var2 = (var2 / 4.0f) + (((float)calib.dig_P4) * 65536.0f);
    var1 = (((float)calib.dig_P3) * var1 * var1 / 524288.0f + ((float)calib.dig_P2) * var1) / 524288.0f;
    var1 = (1.0f + var1 / 32768.0f) * ((float)calib.dig_P1);

    if (var1 == 0.0f)
        return 0.0f; /* avoid divide-by-zero */

    p = 1048576.0f - (float)adc_P;
    p = (p - (var2 / 4096.0f)) * 6250.0f / var1;
    var1 = ((float)calib.dig_P9) * p * p / 2147483648.0f;
    var2 = p * ((float)calib.dig_P8) / 32768.0f;
    p = p + (var1 + var2 + ((float)calib.dig_P7)) / 16.0f;

    return p / 100.0f; /* Pa -> hPa */
}

HAL_StatusTypeDef BMP280_ReadData(I2C_HandleTypeDef *hi2c, BMP280_Data *data)
{
    uint8_t buf[6];

    if (BMP280_ReadReg(hi2c, BMP280_REG_PRESS_MSB, buf, 6) != HAL_OK)
        return HAL_ERROR;

    int32_t adc_P = ((int32_t)buf[0] << 12) | ((int32_t)buf[1] << 4) | (buf[2] >> 4);
    int32_t adc_T = ((int32_t)buf[3] << 12) | ((int32_t)buf[4] << 4) | (buf[5] >> 4);

    data->temperature = BMP280_CompensateTemperature(adc_T);
    data->pressure     = BMP280_CompensatePressure(adc_P);

    /* Standard atmosphere approximation for altitude, sea-level = 1013.25 hPa */
    data->altitude = 44330.0f * (1.0f - powf(data->pressure / 1013.25f, 0.1903f));

    return HAL_OK;
}

/* =========================================================================
 *                          WE10 WiFi / MQTT DRIVER
 * ========================================================================= */

void WE10_Init(char *SSID, char *PASSWD)
{
    char buffer[128];
    HAL_StatusTypeDef status;

    /* Local helper: send a command and print the response */
    void send_cmd(const char *cmd)
    {
        HAL_UART_Transmit(&huart1, (uint8_t *)cmd, strlen(cmd), 1000);
        HAL_UART_Transmit(&huart2, (uint8_t *)cmd, strlen(cmd), 1000);

        memset(buffer, 0, sizeof(buffer));
        status = HAL_UART_Receive(&huart1, (uint8_t *)buffer, sizeof(buffer) - 1, 2000);
        HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 1000);

        if (status != HAL_OK) {
            printf("Error receiving response for %s\n", cmd);
        } else {
            printf("Response for %s: %s\n", cmd, buffer);
        }
    }

    /********* CMD+RESET **********/
    send_cmd("CMD+RESET\r\n");
    HAL_Delay(5000);

    /********* CMD+WIFIMODE=1 **********/
    send_cmd("CMD+WIFIMODE=1\r\n");
    HAL_Delay(2000);

    /********* CMD+CONTOAP=SSID,PASSWD **********/
    sprintf(buffer, "CMD+CONTOAP=%s,%s\r\n", SSID, PASSWD);
    send_cmd(buffer);
    HAL_Delay(5000);

    /********* CMD?WIFI **********/
    send_cmd("CMD?WIFI\r\n");
    HAL_Delay(2000);
}

void MQTT_Init(void)
{
    char buffer[128];

    /* Local helper: send a command and print the response */
    void send_cmd(const char *cmd)
    {
        HAL_StatusTypeDef status;

        HAL_UART_Transmit(&huart1, (uint8_t *)cmd, strlen(cmd), 1000);
        HAL_UART_Transmit(&huart2, (uint8_t *)cmd, strlen(cmd), 1000);

        memset(buffer, 0, sizeof(buffer));
        status = HAL_UART_Receive(&huart1, (uint8_t *)buffer, sizeof(buffer) - 1, 2000);

        printf("Command: %s\n", cmd);
        if (status == HAL_OK) {
            printf("Response: %s\n", buffer);
        } else if (status == HAL_TIMEOUT) {
            printf("Response timeout for command: %s\n", cmd);
        } else {
            printf("Error receiving response for command: %s\n", cmd);
        }
    }

    /********* CMD+MQTTNETCFG **********/
    send_cmd("CMD+MQTTNETCFG=dev.rightech.io,1883\r\n");
    HAL_Delay(2000);

    /********* CMD+MQTTCONCFG **********
     * Replace the client-id string below with your own Rightech client id. */
    send_cmd("CMD+MQTTCONCFG=3,mqtt-korukondagirishkumar04-448evl,,,,,,,,,\r\n");
    HAL_Delay(2000);

    /********* CMD+MQTTSTART **********/
    send_cmd("CMD+MQTTSTART=1\r\n");
    HAL_Delay(5000);

    /********* CMD+MQTTSUB **********/
    send_cmd("CMD+MQTTSUB=base/relay/led1\r\n");
    HAL_Delay(2000);
}

void mqtt_publish_bmp280(float temperature, float pressure, float altitude)
{
    char buffer[128];
    char temp_msg[16];
    char press_msg[16];
    char alt_msg[16];

    /* Format each float as "xx.x" (1 decimal place), no external float printf needed */
    int temp_int  = (int)(temperature * 10);
    int press_int = (int)(pressure * 10);
    int alt_int   = (int)(altitude * 10);

    sprintf(temp_msg,  "%d.%d", temp_int  / 10, abs(temp_int  % 10));
    sprintf(press_msg, "%d.%d", press_int / 10, abs(press_int % 10));
    sprintf(alt_msg,   "%d.%d", alt_int   / 10, abs(alt_int   % 10));

    /* Debug over huart2 */
    char debug_msg[128];
    sprintf(debug_msg, "BMP280 - Temp: %sC, Pressure: %shPa, Altitude: %sm\r\n",
            temp_msg, press_msg, alt_msg);
    HAL_UART_Transmit(&huart2, (uint8_t *)debug_msg, strlen(debug_msg), 1000);

    /* Publish temperature */
    sprintf(buffer, "CMD+MQTTPUB=base/state/temperature,%s\r\n", temp_msg);
    HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), 1000);
    HAL_Delay(1000);

    /* Publish pressure */
    sprintf(buffer, "CMD+MQTTPUB=base/state/pressure,%s\r\n", press_msg);
    HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), 1000);
    HAL_Delay(1000);

    /* Publish altitude */
    sprintf(buffer, "CMD+MQTTPUB=base/state/altitude,%s\r\n", alt_msg);
    HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), 1000);
    HAL_Delay(1000);

    /* Check for incoming messages (e.g. LED control) */
    memset(buffer, 0, sizeof(buffer));
    HAL_StatusTypeDef status = HAL_UART_Receive(&huart1, (uint8_t *)buffer, sizeof(buffer) - 1, 100);

    if (status == HAL_OK && strlen(buffer) > 0) {
        HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 1000);

        for (int i = 0; i < sizeof(buffer); i++) {
            if (buffer[i] == 'N') {
                HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
            } else if (buffer[i] == 'F') {
                HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
            }
        }
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

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
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
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  // Initialize WiFi and MQTT (WE10 module talks over huart1)
  WE10_Init("Hero", "hero1234");
  MQTT_Init();

  // Initialize the BMP280 pressure/temperature sensor over I2C1
  if (BMP280_Init(&hi2c1) != HAL_OK)
  {
    // Sensor not found / not responding - check wiring, address (0x76 vs 0x77)
    Error_Handler();
  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    if (BMP280_ReadData(&hi2c1, &bmp280_data) == HAL_OK)
    {
      mqtt_publish_bmp280(bmp280_data.temperature, bmp280_data.pressure, bmp280_data.altitude);
    }

    HAL_Delay(2000);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Configure the main internal regulator output voltage
  */
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

  /** Initializes the CPU, AHB and APB buses clocks
  */
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
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 83;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
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
  * @brief USART2 Initialization Function
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
  /* User can add his own implementation to report the HAL error return state */
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
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
