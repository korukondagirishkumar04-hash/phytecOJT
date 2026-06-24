#include<stdio.h>
#include"operations.h"
int main()
{
	int a=20,b=6;
	printf("Addition is %d\n",add(a,b));
	printf("Subtraction is %d\n",sub(a,b));
	printf("Multiplication is %d\n",mul(a,b));
	printf("Division is %2f\n",divi(a,b));
	return 0;
}
