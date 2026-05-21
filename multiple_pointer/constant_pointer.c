#include<stdio.h>
int main()
{
	int a=10;
	int b=20;
	int *const ptr=&a;
	*ptr=15;
	printf("modified value: %d\n",a);
	return 0;
}
