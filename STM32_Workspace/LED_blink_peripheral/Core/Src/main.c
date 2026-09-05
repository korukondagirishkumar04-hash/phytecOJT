
#include<stm32f4xx.h>
#include<stdint.h>


void delay(void)
{
	for(unsigned int i=0;i<50000;i++);
}
int main(void)
{
	RCC->CR=(1<<0);
	RCC->AHB1ENR |=(1<<0);


	GPIOA->MODER &=~(3<<10);
	GPIOA->MODER |=(1<<10);
	while(1)
	{
		GPIOA->ODR &=~(1<<5);
		delay();
		GPIOA->ODR |=(1<<5);
		delay();
	}
}
