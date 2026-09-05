#ifndef DHT11_H
#define DHT11_H

#include "main.h"

#define DHT11_PORT GPIOA
#define DHT11_PIN  GPIO_PIN_6

typedef struct {
    float temperature;
    float humidity;
} DHT11_Data;

/* Timer used for the microsecond delay (started with HAL_TIM_Base_Start in main.c) */
extern TIM_HandleTypeDef htim1;

/* Raw bytes / status kept for debug printing in we10.c */
extern uint8_t  Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
extern uint16_t SUM;
extern uint8_t  Presence;

void delay_us(uint16_t us);
void DHT11_Start(void);
uint8_t DHT11_Check_Response(void);
uint8_t DHT11_Read_Byte(void);
void DHT11_Read_Data(DHT11_Data *data);

#endif /* DHT11_H */
