#include "ultrasonic.h"

static TIM_HandleTypeDef *_htim;

void Ultrasonic_Init(TIM_HandleTypeDef *htim)
{
    _htim = htim;
    HAL_TIM_Base_Start(_htim);

    /* Ensure TRIG is low initially */
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);
}

static void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(_htim, 0);
    while (__HAL_TIM_GET_COUNTER(_htim) < us);
}

uint32_t Ultrasonic_Read_cm(void)
{
    uint32_t local_time = 0;

    /* Send 10us trigger pulse */
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);
    delay_us(2);
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
    delay_us(10);
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);

    /* Wait for ECHO to go HIGH */
    while (!(HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN)));

    /* Count how long ECHO stays HIGH */
    __HAL_TIM_SET_COUNTER(_htim, 0);
    while (HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN))
    {
        local_time = __HAL_TIM_GET_COUNTER(_htim);
        if (local_time > 38000) break; /* Timeout ~38ms = no object */
    }

    /* Distance = time(us) / 58 (speed of sound formula) */
    return local_time / 58;
}

uint8_t Ultrasonic_ObstacleDetected(void)
{
    uint32_t dist = Ultrasonic_Read_cm();
    return (dist > 0 && dist <= OBSTACLE_THRESHOLD_CM) ? 1 : 0;
}
