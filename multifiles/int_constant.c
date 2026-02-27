#include<stdio.h>
int main()
{
	int a=10;
	int b=45;
	int*const ptr = &a;
	*ptr=15;
	printf("modified value:%d",a);
	// ptr=&a;
	 return 0;
}

