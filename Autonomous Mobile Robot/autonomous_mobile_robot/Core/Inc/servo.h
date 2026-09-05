#ifndef SERVO_H
#define SERVO_H

#include "main.h"

/*
 * TIM4 CH3 on PB8
 * Period = 19999 → 50Hz (20ms)
 * Pulse range:
 *   500  = 0.5ms = 0°
 *   1499 = 1.5ms = 90° (center)
 *   2500 = 2.5ms = 180°
 */
#define SERVO_0_DEG     500
#define SERVO_90_DEG    1499
#define SERVO_180_DEG   2500

/* Sweep delay between steps in ms */
#define SERVO_SWEEP_DELAY_MS  15

/* Function prototypes */
void Servo_Init(TIM_HandleTypeDef *htim);
void Servo_SetAngle(uint8_t angle);
void Servo_Sweep(void);

#endif /* SERVO_H */
