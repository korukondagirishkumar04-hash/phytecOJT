#include "stm32f4xx.h"

int main(void)
{
    /* Enable clocks: GPIOC and GPIOD */
    RCC->AHB1ENR |= 0x0F;   // GPIOC (bit2) + GPIOD (bit3)

    /*PA6 = OUTPUT*/
     GPIOA->MODER &= ~0x00003000;
     GPIOA->MODER |=  0x00001000;

     /*PB3 = OUTPUT*/
     GPIOB->MODER &= ~0x000000C0;
     GPIOB->MODER |=  0x00000040;


    /* PC7 = output */
    GPIOC->MODER &= ~0x0000C000;
    GPIOC->MODER |=  0x00004000;

    /* PD2 = output */
    GPIOD->MODER &= ~0x00000030;
    GPIOD->MODER |=  0x00000010;

    /* PC13 = input + pull-up */
    GPIOC->MODER &= ~0x0C000000;
    GPIOC->PUPDR &= ~0x0C000000;
    GPIOC->PUPDR |=  0x04000000;

    /* Both LEDs OFF at start */
    GPIOC->BSRR = 0x00800000;   /* PC7 OFF */
    GPIOD->BSRR = 0x00040000;   /* PD2 OFF */
    GPIOA->BSRR = 0x00000040;   /* PA6 OFF */
    GPIOB->BSRR = 0x00000008;   /* PB3 OFF */

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
            if (state >4) state = 0;

            /* turn of all leds */
            GPIOC->BSRR = 0x00800000;   /* PC7 OFF */
            GPIOD->BSRR = 0x00040000;   /* PD2 OFF */
            GPIOA->BSRR = 0x00000040;   /* PA6 OFF */
            GPIOB->BSRR = 0x00000008;   /* PB6 OFF */
           /* turn on one led based on state*/
            if      (state == 1) GPIOC->BSRR = 0x00000080; /* PC7 ON */
            else if (state == 2) GPIOD->BSRR = 0x00000004; /* PD2 ON */
            else if (state == 3) GPIOA->BSRR = 0x00000040; /* PA6 ON */
            else if (state == 4) GPIOB->BSRR = 0x00000008; /* PB3 ON */
            /* state == 0: both OFF */
        }

        prev_btn = btn;

        volatile int dl = 8000;
        while (dl--);
    }
}
