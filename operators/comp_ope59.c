#include<stdio.h>
int main()
{
	int a=67;
	a >>= 6;
	printf("rightshift:%d\n",a);
	a <<= 7;
	printf("leftshift:%d\n",a);
	return 0;
}
