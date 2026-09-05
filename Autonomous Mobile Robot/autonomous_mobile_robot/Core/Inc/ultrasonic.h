#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "main.h"

/* Pin definitions */
#define TRIG_PORT   GPIOB
#define TRIG_PIN    GPIO_PIN_0
#define ECHO_PORT   GPIOB
#define ECHO_PIN    GPIO_PIN_1

/* Obstacle threshold in centimeters */
#define OBSTACLE_THRESHOLD_CM   20

/* Function prototypes */
void Ultrasonic_Init(TIM_HandleTypeDef *htim);
uint32_t Ultrasonic_Read_cm(void);
uint8_t Ultrasonic_ObstacleDetected(void);

#endif /* ULTRASONIC_H */
