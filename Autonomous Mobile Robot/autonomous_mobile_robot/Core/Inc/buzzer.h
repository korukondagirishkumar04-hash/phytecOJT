#ifndef BUZZER_H
#define BUZZER_H

#include "main.h"

/* Pin definitions */
#define BUZZER_PORT GPIOC
#define BUZZER_PIN  GPIO_PIN_6

/* Function prototypes */
void Buzzer_Init(void);
void Buzzer_On(void);
void Buzzer_Off(void);
void Buzzer_Beep(uint32_t duration_ms);

#endif /* BUZZER_H */
