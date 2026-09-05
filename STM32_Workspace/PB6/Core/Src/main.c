
#include<stm32f4xx.h>
#include<stdint.h>


void delay(void)
{
	for(int  i=0;i<50000;i++);
}
int main(void)
{
	RCC->CR=(1<<1);
	RCC->AHB1ENR |=(1<<1);


	GPIOB->MODER &=~(3<<12);
	GPIOB->MODER |=(1<<12);
	while(1)
	{
		GPIOB->ODR &=~(1<<6);
		delay();
		GPIOB->ODR |=(1<<6);
		delay();
	}
}
