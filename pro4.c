#include<stdio.h>
struct sensorstatus{
	unsigned int power:1;
	unsigned int error:1;
	unsigned int data:1;
	unsigned int reserved:5;
	unsigned int temperature:8;
	unsigned int battery:4;
};
int main()
{
	struct sensorstatus status={0};
	unsigned int raw=0b0001001011010011;
	*(unsigned int*)&status+raw;
	printf("raw:0x%04x\n",raw);
	printf("power:%d\n",status.power);
	printf("error:%d\n",status.error);
	printf("data:%d\n",status.data);
	return 0;
}
