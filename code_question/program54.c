//program to a set specific bit of a number using OR
#include<stdio.h>
int main()
{
	int n=5;
	n=n|(1<<1);
	printf("Result is %d",n);
	return 0;
}
