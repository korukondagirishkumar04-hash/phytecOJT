#include<stdio.h>
struct GPIO_Config
{
	unsigned int pin0_mode :2;
	unsigned int pin1_mode :2;
        unsigned int reserved1 :12;
        unsigned int pullup_en :1;
        unsigned int pulldown_en :1;
        unsigned int speed :2;
        unsigned int reserved2 :14;
};
int main(){
	struct 	GPIO_Config GPIO={0};
	GPIO.pin0_mode=1;
	GPIO.pin1_mode=0;
	GPIO.pullup_en=1;
	GPIO.pulldown_en=0;
	GPIO.speed =2;
	printf("GPIO config register value: 0x%08X\n",*(unsigned int*)&GPIO);
	return 0;
}


 
