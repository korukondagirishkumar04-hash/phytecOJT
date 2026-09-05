#include "buzzer.h"

void Buzzer_Init(void)
{
    /* GPIO already configured as output by MX_GPIO_Init.
     * Ensure buzzer starts OFF. */
    HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);
}

void Buzzer_On(void)
{
    HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_SET);
}

void Buzzer_Off(void)
{
    HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);
}

/* Blocking beep for given duration in milliseconds */
void Buzzer_Beep(uint32_t duration_ms)
{
    Buzzer_On();
    HAL_Delay(duration_ms);
    Buzzer_Off();
}
