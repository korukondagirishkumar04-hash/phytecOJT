#include "stm32f4xx.h"

void delayMs(int n);

int main(void)
{
    RCC->AHB1ENR |= 0x04;

    GPIOC->MODER &= ~0x0000FFFF;
    GPIOC->MODER |=  0x00005555;

    while(1)
    {
        GPIOC->ODR = 0xC0;
        delayMs(1000);

        GPIOC->ODR = 0xF9;
        delayMs(1000);

        GPIOC->ODR = 0xA4;
        delayMs(1000);

        GPIOC->ODR = 0xB0;
        delayMs(1000);

        GPIOC->ODR = 0x99;
        delayMs(1000);

        GPIOC->ODR = 0x92;
        delayMs(1000);

        GPIOC->ODR = 0x82;
        delayMs(1000);

        GPIOC->ODR = 0xF8;
        delayMs(1000);

        GPIOC->ODR = 0x80;
        delayMs(1000);

        GPIOC->ODR = 0x90;
        delayMs(1000);

        GPIOC->ODR = 0x7F;
        delayMs(1000);
    }
}

void delayMs(int n)
{
    int i;

    for(; n > 0; n--)
        for(i = 0; i < 3195; i++);
}
