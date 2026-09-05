#include "stm32f4xx.h"
#include <stdint.h>

void uart6_init(void);
void uart6_write(int ch);
void uart6_write_string(char *str);
char uart6_read(void);
void uart6_read_string(char *buffer, int max_len);

void uart2_init(void);
void uart2_write(int ch);
void uart2_write_string(char *str);

int main(void)
{
    char rx_buffer[100];

    uart2_init();
    uart6_init();

    uart2_write_string("Board A Started\r\n");

    for (volatile int d = 0; d < 5000000; d++);

    while (1)
    {
        uart6_write_string("STM32 Board A Data Sent\r\n");

        uart2_write_string("STM32 Board A Data Sent\r\n");

        uart6_read_string(rx_buffer, sizeof(rx_buffer));

        uart2_write_string(rx_buffer);

        for (volatile int i = 0; i < 2000000; i++);
    }
}

/* USART2 */

void uart2_init(void)
{
    RCC->AHB1ENR |= (1 << 0);
    RCC->APB1ENR |= (1 << 17);

    GPIOA->MODER &= ~(0xF << 4);
    GPIOA->MODER |=  (0xA << 4);

    GPIOA->AFR[0] &= ~(0xFF << 8);
    GPIOA->AFR[0] |=  (0x77 << 8);

    USART2->BRR = 0x008B;

    USART2->CR1 |= (1 << 3);

    USART2->CR1 |= (1 << 13);
}

void uart2_write(int ch)
{
    while (!(USART2->SR & (1 << 7)));

    USART2->DR = (ch & 0xFF);
}

void uart2_write_string(char *str)
{
    while (*str)
    {
        uart2_write(*str++);
    }
}

/* USART6 */

void uart6_init(void)
{
    RCC->AHB1ENR |= (1 << 2);

    RCC->APB2ENR |= (1 << 5);

    GPIOC->MODER &= ~(0xF << 12);
    GPIOC->MODER |=  (0xA << 12);

    GPIOC->AFR[0] &= ~(0xFF000000);
    GPIOC->AFR[0] |=  (0x88000000);

    USART6->BRR = 0x008B;

    USART6->CR1 |= (1 << 3) | (1 << 2);

    USART6->CR1 |= (1 << 13);
}

void uart6_write(int ch)
{
    while (!(USART6->SR & (1 << 7)));

    USART6->DR = (ch & 0xFF);
}

char uart6_read(void)
{
    while (!(USART6->SR & (1 << 5)));

    return (char)(USART6->DR & 0xFF);
}

void uart6_write_string(char *str)
{
    while (*str)
    {
        uart6_write(*str++);
    }
}

void uart6_read_string(char *buffer, int max_len)
{
    char data;
    int idx = 0;

    while (idx < (max_len - 1))
    {
        data = uart6_read();

        if (data == '\r')
        {
            continue;
        }

        buffer[idx++] = data;

        if (data == '\n')
        {
            break;
        }
    }

    buffer[idx] = '\0';
}
