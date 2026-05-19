//Demonstrate underflow in float datatype
#include<stdio.h>
#include<float.h>
int main()
{
	float f=FLT_MIN;
	printf("Small float is %e\n",f);
	f=f/1000000;
	printf("After underflow is %e\n",f);
	return 0;
}
