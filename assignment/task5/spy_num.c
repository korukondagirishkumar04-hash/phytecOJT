#include<stdio.h>
int main()
{
	int num,sum=0,digit,product=1;
	printf("Enter number");
	scanf("%d",&num);
	while(num!=0)
	{
		digit = num%10;
		sum= digit+sum;
		product=product*digit;
		num=num/10;
	}
	if(sum==product)
	{
	printf("given number is a spy number");
	}
	else
	{
		printf("given number is not a spy number");
	}
	return 0;
}
