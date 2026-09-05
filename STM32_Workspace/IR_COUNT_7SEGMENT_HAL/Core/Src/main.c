/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>
#include <string.h>

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* Segment codes for 0–9 */
uint8_t seg[10] = {
    0x3F,0x06,0x5B,0x4F,0x66,
    0x6D,0x7D,0x07,0x7F,0x6F
};

/* Map segment pins for Tens digit (PC0–PC6) */
uint16_t tensPins[7] = {
    GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2,
    GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6
};

/* Map segment pins for Ones digit (PB0–PB6) */
uint16_t onesPins[7] = {
    GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2,
    GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6
};

/* Write pattern to PC0–PC6 (Tens digit) */
void DisplayTens(uint8_t digit) {
    uint8_t pattern = seg[digit];
    for(int i=0;i<7;i++){
        HAL_GPIO_WritePin(GPIOC, tensPins[i],
            (pattern&(1<<i))? GPIO_PIN_RESET:GPIO_PIN_SET);
    }
}

/* Write pattern to PB0–PB6 (Ones digit) */
void DisplayOnes(uint8_t digit) {
    uint8_t pattern = seg[digit];
    for(int i=0;i<7;i++){
        HAL_GPIO_WritePin(GPIOB, onesPins[i],
            (pattern&(1<<i))? GPIO_PIN_RESET:GPIO_PIN_SET);
    }
}

/* Show two digits */
void DisplayTwoDigits(uint8_t num) {
    uint8_t tens = num / 10;
    uint8_t ones = num % 10;
    DisplayTens(tens);
    DisplayOnes(ones);
}

/* Function prototypes -------------------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  volatile uint8_t count = 0;
  GPIO_PinState prev_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

  DisplayTwoDigits(0);
  char msg[] = "Count = 0\r\n";
  HAL_UART_Transmit(&huart2,(uint8_t*)msg,strlen(msg),HAL_MAX_DELAY);

  while (1)
  {
    GPIO_PinState current_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

    if((prev_state == GPIO_PIN_SET) && (current_state == GPIO_PIN_RESET)) {
        count++;
        if(count > 99) count = 0;

        DisplayTwoDigits(count);

        char buffer[20];
        sprintf(buffer,"Count=%d\r\n",count);
        HAL_UART_Transmit(&huart2,(uint8_t*)buffer,strlen(buffer),HAL_MAX_DELAY);

        HAL_Delay(300); // debounce
    }
    prev_state = current_state;
  }
}

/* System Clock Configuration */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;   // USB OTG FS clock

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }
}

/* USART2 Initialization */
static void MX_USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK) { Error_Handler(); }
}

/* GPIO Initialization */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // PC0–PC6 for Tens digit
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|
                        GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  // PB0–PB6 for Ones digit
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|
                        GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  // PA0 for IR sensor input
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/* Error Handler */
void Error_Handler(void)
{
  __disable_irq();
  while (1) { }
}
