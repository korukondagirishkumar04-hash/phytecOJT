#include "stm32f4xx.h"
void delay(int delay)
{
	for(int i=0;i<delay;i++);
}
int main()
{
RCC->AHB1ENR|=(1<<1);
GPIOB->MODER=0x00000000;
GPIOB->MODER=0X00005555;

while (1)
{
	GPIOB->ODR|='x';
	delay(50000);
}
}
