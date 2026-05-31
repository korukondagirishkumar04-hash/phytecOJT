#include<stdio.h>
<<<<<<< HEAD
int main()
{
	int num,original,remainder;
	int sum=0;
	printf("Enter a 3 digit number :");
	scanf("%d",&num);
	original=num;
	while(num!=0)
	{
		remainder=num%10;
		sum=sum+(remainder*remainder*remainder);
		num=num/10;
	}
	if(sum==original)
		printf(" given number is  Armstrong number");
	else
		printf("given number is not a Armstrong number");
=======
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
>>>>>>> cc2f330e8fe3679cc7734622c8a804aa39085974
	return 0;
}


<<<<<<< HEAD
=======
 
>>>>>>> cc2f330e8fe3679cc7734622c8a804aa39085974
