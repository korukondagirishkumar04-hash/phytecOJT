//program to demonstrate bitwise assignments
#include<stdio.h>
int main()
{
	int a=5;
	a&=3; a|=2; a^=1;
	printf("Result  is %d",a);
	return 0;
}
