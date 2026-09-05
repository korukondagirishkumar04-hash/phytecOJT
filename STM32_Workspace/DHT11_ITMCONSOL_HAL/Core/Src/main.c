/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : DHT11 with ITM SWO Console Output
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct
{
    float temperature;
    float humidity;
} DHT11_Data;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DHT11_PORT GPIOA
#define DHT11_PIN  GPIO_PIN_6
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
uint16_t SUM, RH, TEMP;
uint8_t presence = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM1_Init(void);

/* USER CODE BEGIN PFP */
void DHT11_Start(void);
int8_t DHT11_Check_Response(void);
uint8_t DHT11_Read(void);
void delay_us(uint16_t us);
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

// Route printf to ITM SWO
int __io_putchar(int ch)
{
    ITM_SendChar(ch);
    return ch;
}

// Microsecond delay using TIM1
void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

// ✅ DHT11 Start Signal
void DHT11_Start(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Configure PA6 as Output
    GPIO_InitStruct.Pin   = DHT11_PIN;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);

    // Pull LOW for 18ms (start signal)
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET);
    HAL_Delay(18);

    // Release HIGH for 30us
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);
    delay_us(30);

    // Switch to Input with Pull-up to listen for DHT11 response
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

// Check DHT11 Response with timeout protection
int8_t DHT11_Check_Response(void)
{
    uint16_t timeout;

    // Wait for DHT11 to pull line LOW (max 100us)
    timeout = 0;
    while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
    {
        delay_us(1);
        if (++timeout > 100)
        {
            printf("Timeout: DHT11 did not pull LOW\r\n");
            return 0;
        }
    }



    // Wait 80us — line should go HIGH
    delay_us(80);
    if (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)))
    {
        printf("Timeout: DHT11 did not go HIGH after LOW\r\n");
        return -1;
    }

    // Wait for line to go LOW again (end of response pulse)
    timeout = 0;
    while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
    {
        delay_us(1);
        if (++timeout > 100)
        {
            printf("Timeout: DHT11 response pulse too long\r\n");
            return -1;
        }
    }

    return 1; // ✅ Good response
}

// Read one byte from DHT11 with timeout protection
uint8_t DHT11_Read(void)
{
    uint8_t i = 0, j;
    uint16_t timeout;

    for (j = 0; j < 8; j++)
    {
        // Wait for line to go HIGH (start of bit)
        timeout = 0;
        while (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)))
        {
            delay_us(1);
            if (++timeout > 100) return i;
        }

        // Sample at 40us
        delay_us(40);

        if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
            i |= (1 << (7 - j));   // Bit = 1
        else
            i &= ~(1 << (7 - j));  // Bit = 0

        // Wait for line to go LOW (end of bit)
        timeout = 0;
        while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
        {
            delay_us(1);
            if (++timeout > 100) return i;
        }
    }
    return i;
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

    HAL_Init();

    /* USER CODE BEGIN Init */
    /* USER CODE END Init */

    SystemClock_Config();

    /* USER CODE BEGIN SysInit */
    /* USER CODE END SysInit */

    MX_GPIO_Init();
    MX_USART2_UART_Init();
    MX_TIM1_Init();

    /* USER CODE BEGIN 2 */

    // Start TIM1 for microsecond delay
    HAL_TIM_Base_Start(&htim1);

    // Enable ITM Stimulus Port 0
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    ITM->LAR  = 0xC5ACCE55;
    ITM->TCR |= ITM_TCR_ITMENA_Msk;
    ITM->TER |= 1;

    // ✅ Wait 1 second for DHT11 to stabilize after power-on
    HAL_Delay(1000);
    printf("DHT11 ITM Test Starting...\r\n");

    /* USER CODE END 2 */

    /* USER CODE BEGIN WHILE */
    while (1)
    {
        DHT11_Start();
        presence = DHT11_Check_Response();

        if (presence == 1)
        {
            Rh_byte1   = DHT11_Read();
            Rh_byte2   = DHT11_Read();
            Temp_byte1 = DHT11_Read();
            Temp_byte2 = DHT11_Read();
            SUM        = DHT11_Read();

            TEMP = Temp_byte1;
            RH   = Rh_byte1;

            uint8_t checksum = Rh_byte1 + Rh_byte2 + Temp_byte1 + Temp_byte2;

            if (checksum == SUM)
            {
                printf("Temp: %d C  Humidity: %d%%\r\n", TEMP, RH);
            }
            else
            {
                printf("Checksum error! Calc=%d  Received=%d\r\n", checksum, SUM);
            }
        }
        else if (presence == -1)
        {
            printf("DHT11 Response Error!\r\n");
        }
        else
        {
            printf("No response from DHT11! Check wiring.\r\n");
        }

        HAL_Delay(2000);
    }
    /* USER CODE END WHILE */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

    RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource       = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM            = 16;
    RCC_OscInitStruct.PLL.PLLN            = 336;
    RCC_OscInitStruct.PLL.PLLP            = RCC_PLLP_DIV4;
    RCC_OscInitStruct.PLL.PLLQ            = 2;
    RCC_OscInitStruct.PLL.PLLR            = 2;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType      = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                     | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief TIM1 Initialization Function
  * @retval None
  */
static void MX_TIM1_Init(void)
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig     = {0};

    htim1.Instance               = TIM1;
    htim1.Init.Prescaler         = 83;       // 84MHz / (83+1) = 1MHz → 1 tick = 1us
    htim1.Init.CounterMode       = TIM_COUNTERMODE_UP;
    htim1.Init.Period             = 65535;
    htim1.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
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
    sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief USART2 Initialization Function
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{
    huart2.Instance          = USART2;
    huart2.Init.BaudRate     = 115200;
    huart2.Init.WordLength   = UART_WORDLENGTH_8B;
    huart2.Init.StopBits     = UART_STOPBITS_1;
    huart2.Init.Parity       = UART_PARITY_NONE;
    huart2.Init.Mode         = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief GPIO Initialization Function
  * @retval None
  */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    // ✅ LD2 LOW, DHT11 pin HIGH (idle state)
    HAL_GPIO_WritePin(GPIOA, LD2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);

    // B1 button
    GPIO_InitStruct.Pin  = B1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

    // LD2 as output
    GPIO_InitStruct.Pin   = LD2_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // ✅ PA6 (DHT11) as output, initially HIGH (idle)
    GPIO_InitStruct.Pin   = GPIO_PIN_6;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  Error Handler
  * @retval None
  */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    __disable_irq();
    while (1) {}
    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
