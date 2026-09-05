#include "stm32f4xx.h"

#define GPIO_EN   (1U << 0)   // AHB1ENR bit 0  → GPIOA clock
#define PA6_MOD   (1U << 12)  // MODER bit 12   → PA6 output (lower bit of [13:12])
#define PA6_ODR   (1U << 6)   // ODR   bit 6    → PA6 pin voltage

void delay(volatile uint32_t count)
{
    while (count--);
}

int main(void)
{
    // Step 1 — Enable GPIOA clock
    RCC->AHB1ENR |= GPIO_EN;

    // Step 2 — Set PA6 as output (clear first, then set)
    GPIOA->MODER &= ~(3U << (6 * 2));  // Clear bits [13:12] → 00
    GPIOA->MODER |=  PA6_MOD;          // Set  bits [13:12] → 01 (output)

    // Step 3 — Blink using ODR only
    while (1)
    {
        GPIOA->ODR |=  PA6_ODR;    // Set   bit 6 → PA6 = 3.3V → LED ON
        delay(500000);

        GPIOA->ODR &= ~PA6_ODR;   // Clear bit 6 → PA6 = 0V   → LED OFF
        delay(500000);
    }

    return 0;
}
