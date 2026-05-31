<<<<<<< HEAD
#include<stdio.h>
int main()
{
	int num,reverse=0,reminder;
	printf("Enter a number:");
	scanf("%d",&num);
	while(num!=0)
	{
		reminder = num % 10;
		reverse = reverse * 10 + reminder;
		num = num/10;
	}
	printf("Reversed num=%d",reverse);
=======
#include <stdio.h>
struct sensorstatus{
	unsigned int power:1;
	unsigned int error:1;
	unsigned int data:1;
	unsigned int reserved:5;
	unsigned int temperature:8;
	unsigned int battert:4;
};
int main()
{
	struct sensorstatus status={0};
	unsigned int raw=0b0001001011010011;
	*(unsigned int *)&status =raw;
	printf("raw:0x%04X\n",raw);
	printf("power:%d\n",status.power);
	printf("error:%d\n",status.error);
	printf("data:%d\n",status.data);
>>>>>>> cc2f330e8fe3679cc7734622c8a804aa39085974
	return 0;
}
