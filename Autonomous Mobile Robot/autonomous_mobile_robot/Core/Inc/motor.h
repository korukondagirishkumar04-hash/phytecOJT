#ifndef MOTOR_H
#define MOTOR_H

#include "main.h"

/* L298N Direction pins */
#define MOTOR_IN1_PORT  GPIOB
#define MOTOR_IN1_PIN   GPIO_PIN_4

#define MOTOR_IN2_PORT  GPIOB
#define MOTOR_IN2_PIN   GPIO_PIN_5

#define MOTOR_IN3_PORT  GPIOB
#define MOTOR_IN3_PIN   GPIO_PIN_6

#define MOTOR_IN4_PORT  GPIOB
#define MOTOR_IN4_PIN   GPIO_PIN_7

/* PWM speed range: 0 to 999 (matches TIM3 period) */
#define MOTOR_MAX_SPEED     999
#define MOTOR_DEFAULT_SPEED 750   /* ~75% duty cycle */
#define MOTOR_TURN_SPEED    500   /* ~50% duty cycle for turning */

/* Motor status strings for logging */
#define MOTOR_STATUS_FORWARD    "FORWARD"
#define MOTOR_STATUS_BACKWARD   "BACKWARD"
#define MOTOR_STATUS_LEFT       "TURNING LEFT"
#define MOTOR_STATUS_RIGHT      "TURNING RIGHT"
#define MOTOR_STATUS_STOP       "STOPPED"

/* Function prototypes */
void Motor_Init(TIM_HandleTypeDef *htim);
void Motor_Forward(uint16_t speed);
void Motor_Backward(uint16_t speed);
void Motor_Turn_Left(uint16_t speed);
void Motor_Turn_Right(uint16_t speed);
void Motor_Stop(void);
const char* Motor_GetStatus(void);

#endif /* MOTOR_H */
