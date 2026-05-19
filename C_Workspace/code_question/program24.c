//Demonstrate Type casting in arithmetic expression
#include<stdio.h>
int main()
{
	int a=8,b=2;
	float result,result1,result2,result3;
	result=(float)a/b;
	result1=(float)a+b;
	result2=(float)a-b;
	result3=(float)a*b;
	printf("Result is %f\n",result);
	printf("Result is %f\n",result1);
	printf("Result is %f\n",result2);
	printf("Reult is %f\n",result3);
	return 0;
}

