#include<stdio.h>
int main()
{
	int num,square,sum=0;
	printf("Enter thr number ");
	scanf("%d",&num);
	square=num*num;
	while(square > 0)
	{
		sum=sum+square%10;
		square=square/10;
	}
	if(sum==num)
	{
		printf("The given number is neon number");
	}
	else
	{
		printf("The given number is not a neon number");
	}
	return 0;
}
