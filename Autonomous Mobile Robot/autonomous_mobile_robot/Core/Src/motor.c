#include "motor.h"

static TIM_HandleTypeDef *_htim;
static const char *_status = MOTOR_STATUS_STOP;

void Motor_Init(TIM_HandleTypeDef *htim)
{
    _htim = htim;

    /* Start PWM on both channels */
    HAL_TIM_PWM_Start(_htim, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(_htim, TIM_CHANNEL_2);

    /* Start with motors stopped */
    Motor_Stop();
}

static void set_speed(uint16_t speedA, uint16_t speedB)
{
    __HAL_TIM_SET_COMPARE(_htim, TIM_CHANNEL_1, speedA);
    __HAL_TIM_SET_COMPARE(_htim, TIM_CHANNEL_2, speedB);
}

void Motor_Forward(uint16_t speed)
{
    /* Motor A forward */
    HAL_GPIO_WritePin(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_PIN_RESET);

    /* Motor B forward */
    HAL_GPIO_WritePin(MOTOR_IN3_PORT, MOTOR_IN3_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(MOTOR_IN4_PORT, MOTOR_IN4_PIN, GPIO_PIN_RESET);

    set_speed(speed, speed);
    _status = MOTOR_STATUS_FORWARD;
}

void Motor_Backward(uint16_t speed)
{
    /* Motor A backward */
    HAL_GPIO_WritePin(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_PIN_SET);

    /* Motor B backward */
    HAL_GPIO_WritePin(MOTOR_IN3_PORT, MOTOR_IN3_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_IN4_PORT, MOTOR_IN4_PIN, GPIO_PIN_SET);

    set_speed(speed, speed);
    _status = MOTOR_STATUS_BACKWARD;
}

void Motor_Turn_Left(uint16_t speed)
{
    /* Motor A backward, Motor B forward */
    HAL_GPIO_WritePin(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_PIN_SET);

    HAL_GPIO_WritePin(MOTOR_IN3_PORT, MOTOR_IN3_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(MOTOR_IN4_PORT, MOTOR_IN4_PIN, GPIO_PIN_RESET);

    set_speed(speed, speed);
    _status = MOTOR_STATUS_LEFT;
}

void Motor_Turn_Right(uint16_t speed)
{
    /* Motor A forward, Motor B backward */
    HAL_GPIO_WritePin(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(MOTOR_IN3_PORT, MOTOR_IN3_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_IN4_PORT, MOTOR_IN4_PIN, GPIO_PIN_SET);

    set_speed(speed, speed);
    _status = MOTOR_STATUS_RIGHT;
}

void Motor_Stop(void)
{
    HAL_GPIO_WritePin(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_IN3_PORT, MOTOR_IN3_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_IN4_PORT, MOTOR_IN4_PIN, GPIO_PIN_RESET);

    set_speed(0, 0);
    _status = MOTOR_STATUS_STOP;
}

const char* Motor_GetStatus(void)
{
    return _status;
}
