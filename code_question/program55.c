//program to clear a specific bit of a number using  AND with NOT
#include<stdio.h>
int main()
{
	int n=7;
	n=n&~(1<<1);
	printf("Result is %d",n);
	return 0;
}
