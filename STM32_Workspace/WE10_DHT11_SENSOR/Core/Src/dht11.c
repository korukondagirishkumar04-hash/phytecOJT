#include "dht11.h"

uint8_t  Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
uint16_t SUM;
uint8_t  Presence = 0;

/* Microsecond delay using TIM1 (configured with Prescaler = 83 -> 1us tick @ 84MHz APB2 clock) */
void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

void DHT11_Start(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DHT11_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);

    // Pull the pin low for at least 18ms
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET);
    HAL_Delay(20);

    // Pull the pin high for 20-40us
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);
    delay_us(30);

    // Switch to input to receive data
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

uint8_t DHT11_Check_Response(void)
{
    uint8_t response = 0;

    delay_us(40);
    if (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)))
    {
        delay_us(80);
        response = (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)) ? 1 : 0;
    }

    // Wait for the line to go low again (start of data transmission)
    while ((HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)));

    return response;
}

uint8_t DHT11_Read_Byte(void)
{
    uint8_t data = 0;

    for (uint8_t i = 0; i < 8; i++)
    {
        while (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)));

        delay_us(40);

        if ((HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)))
        {
            data |= (1 << (7 - i));
            while ((HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)));
        }
    }

    return data;
}

void DHT11_Read_Data(DHT11_Data *data)
{
    DHT11_Start();
    Presence = DHT11_Check_Response();

    if (Presence)
    {
        Rh_byte1   = DHT11_Read_Byte();
        Rh_byte2   = DHT11_Read_Byte();
        Temp_byte1 = DHT11_Read_Byte();
        Temp_byte2 = DHT11_Read_Byte();
        SUM        = DHT11_Read_Byte();

        if ((Rh_byte1 + Rh_byte2 + Temp_byte1 + Temp_byte2) == SUM)
        {
            data->humidity    = (float)Rh_byte1 + (float)(Rh_byte2 * 0.1);
            data->temperature = (float)Temp_byte1 + (float)(Temp_byte2 * 0.1);
        }
    }
}
 /*
 * dht11.c
 *
 *  Created on: Jul 15, 2026
 *      Author: K GIRISH KUMAR
 */


