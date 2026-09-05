//calculate factorial using *= inside loop
#include<stdio.h>
int main()
{
	int n=5,i,fact=1;
	for(i=1;i<=n;i++) fact*=i;
	printf("Factorial is %d",fact);
	return 0;
}
