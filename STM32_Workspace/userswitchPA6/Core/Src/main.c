#include "stm32f4xx.h"

int main(void)
{
    /* Enable clocks: GPIOA, GPIOB, GPIOC */
    RCC->AHB1ENR |= 0x07;

    /* PA6 = output */
    GPIOA->MODER &= ~0x00001000;
    GPIOA->MODER |=  0x00001000;

    /* PB3 = output */
    GPIOB->MODER &= ~0x000000C0;
    GPIOB->MODER |=  0x00000040;

    /* PC13 = input + pull-up */
    GPIOC->MODER &= ~0x0C000000;
    GPIOC->PUPDR &= ~0x0C000000;
    GPIOC->PUPDR |=  0x04000000;

    /* Both LEDs OFF at start */
    GPIOA->BSRR = 0x00400000;   /* PA6 OFF */
    GPIOB->BSRR = 0x00080000;   /* PB3 OFF */

    int state    = 0;
    int prev_btn = 1;

    while (1)
    {
        int btn = (GPIOC->IDR & 0x2000) ? 1 : 0;

        if (prev_btn == 1 && btn == 0)
        {
            /* debounce */
            volatile int d = 16000;
            while (d--);

            state++;
            if (state > 2) state = 0;

            /* Clear both LEDs first */
            GPIOA->BSRR = 0x00400000;   /* PA6 OFF */
            GPIOB->BSRR = 0x00080000;   /* PB3 OFF */

            if      (state == 1) GPIOA->BSRR = 0x00000040; /* PA6 ON */
            else if (state == 2) GPIOB->BSRR = 0x00000008; /* PB3 ON */
            /* state == 0: both already OFF */
        }

        prev_btn = btn;

        volatile int dl = 8000;
        while (dl--);
    }
}
