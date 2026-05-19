//factorial
#include<stdio.h>
int main()
{
	int n,fact=1;
	printf("Enter number n  ");
	scanf("%d",&n);
	if(n<0)
	{
		printf("Factorial is not possible");
	}
	else
	{
		while(n>0)
		{
			fact=fact*n;//factorial
			n--;
		}
		printf("factorial is  %d ",fact);
	}
	return 0;
}
