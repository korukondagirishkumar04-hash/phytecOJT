#include<stdio.h>
int main()
{
	int base,exponent,i;
	int result=1;
	printf("Enter base number");
	scanf("%d",&base);
	printf("Enter exponent");
	scanf("%d",&exponent);
	for(i=1;i<=exponent;i++)
	{
		result=result*base;
	}
	printf("result=%d",result);
	return 0;
}
