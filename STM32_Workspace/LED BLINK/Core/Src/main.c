#include <stdint.h>

/* RCC Registers */
#define RCC_CR        (*(volatile uint32_t*)0x40023800)
#define RCC_AHB1ENR   (*(volatile uint32_t*)0x40023830)

/* GPIOA Registers */
#define GPIOA_MODER   (*(volatile uint32_t*)0x40020000)
#define GPIOA_OTYPER  (*(volatile uint32_t*)0x40020004)
#define GPIOA_OSPEEDR (*(volatile uint32_t*)0x40020008)
#define GPIOA_ODR     (*(volatile uint32_t*)0x40020014)

/* Simple delay */
void delay(volatile uint32_t time)
{
    while(time--);
}

int main(void)
{
    /* 1. Enable HSI clock (safe way) */
    RCC_CR |= (1 << 0);


    /* 2. Enable GPIOA clock */
    RCC_AHB1ENR |= (1 << 0);

    /* 3. Configure PA5 as output */
    GPIOA_MODER &= ~(3 << 10);   // clear bits
    GPIOA_MODER |=  (1 << 10);   // set as output

    /* 4. Output type: push-pull */
    GPIOA_OTYPER &= ~(1 << 5);

    /* 5. Speed: medium */
    GPIOA_OSPEEDR &= ~(3 << 10);
    GPIOA_OSPEEDR |=  (1 << 10);

    /* 6. Blink loop */
    while(1)
    {
        GPIOA_ODR |= (1 << 5);   // LED ON
        delay(10000000);

        GPIOA_ODR &= ~(1 << 5);  // LED OFF
        delay(10000000);
    }
}
