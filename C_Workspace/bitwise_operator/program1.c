#include<stdio.h>
int setbit(int register_value,int bit_position)
{
	return register_value|(1<<bit_position);
}
int main()
{
	int gpio_port=0b00000000;
	printf("before is0x%02x)\n",gpio_port);
	gpio_port=setbit(gpio_port,3);
	printf("after turning on bit 3:0x%02x\n",gpio_port);
	return 0;
}
