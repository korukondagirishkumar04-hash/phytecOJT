//Demonstrate overflow in int datatype
#include<stdio.h>
#include<limits.h>
int main()
{
	int a=INT_MAX;
	printf("Max int is %d\n",a);
	a=a+1;
	printf("After overflow is %d\n",a);
	return 0;
}
