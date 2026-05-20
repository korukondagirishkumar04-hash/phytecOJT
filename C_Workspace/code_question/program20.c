//Demonstrate Implicit type promotion in Expression with(int+float)
#include<stdio.h>
int main()
{
	int a=20;
	float b=5.7;
	float result;
	result=a+b;
	printf("Result is %f",result);
	return 0;
}
