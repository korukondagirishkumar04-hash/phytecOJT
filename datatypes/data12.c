#include<stdio.h>
#include<float.h>
int main()
{
	float num=FLT_MIN;
	printf("minimum float value:%e\n",num);
	num=num/10;
	printf("underflow value:%f\n",num);
	return 0;
}
