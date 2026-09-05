#include<stdio.h>
<<<<<<< HEAD
int main()
{
	int num,sum=0,reminder;
	printf("Enter a number :");
	scanf("%d",&num);
	while(num!=0)
	{
		reminder=num%10;
		sum=sum+reminder;
		num=num/10;
	}
	printf("Sum of digits=%d",sum);
	return 0;
}

=======
struct SensorStatus{
	unsigned int power_on:1;
	unsigned int error_flag:1;
	unsigned int data_ready:1;
	unsigned int reserved:5;
	unsigned int temperature:8;
	unsigned int battery:4;
};
int main()
{
	struct SensorStatus status={0};
	unsigned int raw_reg=0b0001001011010011;
	*(unsigned int*)&status=raw_reg;
	printf("Raw register :0x%04X\n",raw_reg);
	printf("Power ON :%d\n",status.power_on);
	printf("Error flag :%d\n",status.error_flag);
	printf("Data ready :%d\n",status.data_ready);
	printf("Temperature :%dC\n",status.temperature);
	printf("Battery level :%d15\n",status.battery);
	return 0;
	}
>>>>>>> cc2f330e8fe3679cc7734622c8a804aa39085974

