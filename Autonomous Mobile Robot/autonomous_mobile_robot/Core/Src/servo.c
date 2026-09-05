#include "servo.h"

static TIM_HandleTypeDef *_htim;

void Servo_Init(TIM_HandleTypeDef *htim)
{
    _htim = htim;
    HAL_TIM_PWM_Start(_htim, TIM_CHANNEL_3);

    /* Center the servo at startup */
    Servo_SetAngle(90);
}

void Servo_SetAngle(uint8_t angle)
{
    if (angle > 180) angle = 180;

    /* Map 0-180 degrees to pulse width 500-2500 */
    uint32_t pulse = SERVO_0_DEG + ((uint32_t)angle * (SERVO_180_DEG - SERVO_0_DEG)) / 180;
    __HAL_TIM_SET_COMPARE(_htim, TIM_CHANNEL_3, pulse);
}

/* Continuously sweeps 0° → 180° → 0°.
 * Call this in a loop or a dedicated task. */
void Servo_Sweep(void)
{
    uint8_t angle;

    /* Sweep 0 to 180 */
    for (angle = 0; angle <= 180; angle++)
    {
        Servo_SetAngle(angle);
        HAL_Delay(SERVO_SWEEP_DELAY_MS);
    }

    /* Sweep 180 to 0 */
    for (angle = 180; angle > 0; angle--)
    {
        Servo_SetAngle(angle);
        HAL_Delay(SERVO_SWEEP_DELAY_MS);
    }
}
