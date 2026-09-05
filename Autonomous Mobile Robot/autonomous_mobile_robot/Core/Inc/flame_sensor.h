#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

#include "main.h"

/* Pin definitions */
#define FLAME_PORT  GPIOC
#define FLAME_PIN   GPIO_PIN_7

/*
 * Most flame sensor modules output LOW when flame is detected,
 * HIGH when no flame. Adjust FLAME_ACTIVE_STATE if yours differs.
 */
#define FLAME_ACTIVE_STATE  GPIO_PIN_RESET

/* Function prototypes */
void Flame_Init(void);
uint8_t Flame_Detected(void);

#endif /* FLAME_SENSOR_H */
