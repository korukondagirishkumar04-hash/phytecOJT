#include "main.h"
#include "string.h"
#include "stm32f4xx_hal.h"

UART_HandleTypeDef huart2;

/* Function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

/* LCD prototypes */
void LCD_init(void);
void LCD_enable(void);
void LCD_SendNibble(uint8_t nibble);
void LCD_data(uint8_t data);
void LCD_cmd(uint8_t cmd);
void LCD_string(char *str);

/* Keypad prototypes */
char Keypad_GetKey(void);

/* Keypad layout */
char keypad[4][4] =
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

/* ---------------- LCD Functions ---------------- */
void LCD_enable(void){
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET); // EN
    HAL_Delay(2);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
}

void LCD_SendNibble(uint8_t nibble){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0,(nibble & 0x01)? GPIO_PIN_SET:GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1,(nibble & 0x02)? GPIO_PIN_SET:GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2,(nibble & 0x04)? GPIO_PIN_SET:GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,(nibble & 0x08)? GPIO_PIN_SET:GPIO_PIN_RESET);
    LCD_enable();
}

void LCD_cmd(uint8_t cmd){
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); // RS=0
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // RW=0
    LCD_SendNibble(cmd>>4);
    LCD_SendNibble(cmd & 0x0F);
    HAL_Delay(2);
}

void LCD_data(uint8_t data){
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);   // RS=1
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // RW=0
    LCD_SendNibble(data>>4);
    LCD_SendNibble(data & 0x0F);
    HAL_Delay(2);
}

void LCD_string(char *str){
    while(*str){
        LCD_data(*str++);
    }
}

void LCD_init(void){
    HAL_Delay(20);
    LCD_SendNibble(0x03); HAL_Delay(5);
    LCD_SendNibble(0x03); HAL_Delay(5);
    LCD_SendNibble(0x03); HAL_Delay(5);
    LCD_SendNibble(0x02); // 4-bit mode

    LCD_cmd(0x28); // 4-bit, 2 line
    LCD_cmd(0x0C); // Display ON, Cursor OFF
    LCD_cmd(0x06); // Entry mode
    LCD_cmd(0x01); // Clear display
    HAL_Delay(2);
}

/* ---------------- Keypad Function ---------------- */
char Keypad_GetKey(void)
{
    uint8_t row, col;
    for(row = 0; row < 4; row++)
    {
        // Set all rows HIGH
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET);

        // Set current row LOW
        HAL_GPIO_WritePin(GPIOC, (GPIO_PIN_0 << row), GPIO_PIN_RESET);

        for(col = 0; col < 4; col++)
        {
            if(HAL_GPIO_ReadPin(GPIOC, (GPIO_PIN_4 << col)) == GPIO_PIN_RESET)
            {
                HAL_Delay(20); // debounce
                while(HAL_GPIO_ReadPin(GPIOC, (GPIO_PIN_4 << col)) == GPIO_PIN_RESET);
                return keypad[row][col];
            }
        }
    }
    return 0; // No key pressed
}

/* ---------------- Main ---------------- */
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    LCD_init();
    LCD_string("Welcome to Keypad");

    LCD_cmd(0xC0); // Move cursor to line 2

    char key;
    int charCount = 0;

    while(1)
    {
        key = Keypad_GetKey();
        if(key)
        {
            LCD_data(key);
            HAL_UART_Transmit(&huart2,
                              (uint8_t *)&key,
                              1,
                              HAL_MAX_DELAY);
            charCount++;

            if(charCount == 12) {
                LCD_cmd(0xC0);   // Jump to line 2 after 12 chars
            }
            if(charCount == 24) {
                LCD_cmd(0x01);   // Clear display after 24 chars
                LCD_cmd(0x80);   // Reset to line 1
                charCount = 0;
            }
        }
    }
}

/* ---------------- GPIO Init ---------------- */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* LCD Pins: PA0=RS, PA1=RW, PA4=EN */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* LCD Data Pins: PB0-PB3 */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Keypad Rows: PC0-PC3 as outputs */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* Keypad Columns: PC4-PC7 as inputs with pull-up */
    GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

/* ---------------- UART Init ---------------- */
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

/* ---------------- System Clock ---------------- */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) { Error_Handler(); }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) { Error_Handler(); }
}

/* ---------------- Error Handler ---------------- */
void Error_Handler(void)
{
    __disable_irq();
    while (1) { }
}
