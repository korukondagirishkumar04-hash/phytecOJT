#include "flame_sensor.h"

void Flame_Init(void)
{
    /* GPIO already configured as input by MX_GPIO_Init.
     * Nothing extra needed here. */
}

uint8_t Flame_Detected(void)
{
    return (HAL_GPIO_ReadPin(FLAME_PORT, FLAME_PIN) == FLAME_ACTIVE_STATE) ? 1 : 0;
}
