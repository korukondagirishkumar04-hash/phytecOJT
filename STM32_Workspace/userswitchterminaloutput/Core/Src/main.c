#include "stm32f4xx.h"

/* USART2 Init (PA2 TX, 9600 baud @16MHz) */
void USART2_init(void)
{
    RCC->AHB1ENR |= 0x00000001;   // GPIOA enable
    RCC->APB1ENR |= 0x00020000;   // USART2 enable

    /* PA2 -> AF mode */
    GPIOA->MODER &= ~0x00000030;
    GPIOA->MODER |=  0x00000020;

    /* AF7 for USART2 */
    GPIOA->AFR[0] &= ~0x00000F00;
    GPIOA->AFR[0] |=  0x00000700;

    USART2->BRR = 0x0683;         // 9600 baud

    USART2->CR1 |= 0x0008;        // TE
    USART2->CR1 |= 0x2000;        // UE
}

/* Send String */
void USART2_Send(char *s)
{
    while (*s)
    {
        while (!(USART2->SR & 0x0080)); // TXE
        USART2->DR = *s++;
    }
}

int main(void)
{
    RCC->AHB1ENR |= 0x00000004;   // GPIOC
    RCC->AHB1ENR |= 0x00000001;   // GPIOA

    USART2_init();

    /* PA5 = output */
    GPIOA->MODER &= ~0x00000C00;
    GPIOA->MODER |=  0x00000400;

    /* PC13 = input */
    GPIOC->MODER &= ~0x0C000000;

    int prev_state = -1;

    while (1)
    {
        int led_state;

        if (GPIOC->IDR & 0x2000)
        {
            GPIOA->BSRR = 0x00200000; // LED OFF
            led_state = 0;
        }
        else
        {
            GPIOA->BSRR = 0x00000020; // LED ON
            led_state = 1;
        }

        /* Print only on change */
        if (led_state != prev_state)
        {
            if (led_state)
                USART2_Send("LED (PA5) ON\r\n");
            else
                USART2_Send("LED (PA5) OFF\r\n");

            prev_state = led_state;
        }
    }
}
