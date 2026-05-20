#include<stdio.h>
int main()
{
	int num,sum;
	printf("Enter a number ");
	scanf("%d",&num);
	while(num>9)
	{
		sum=0;
	while(num>0)
	{
		sum=sum+(num%10);
		num=num/10;
	}
	num=sum;
	}
	if(num==1)
	{
		printf("The given number is magic number");
	}
	else
	{
		printf("The given number is not a magic number");
	}
	return 0;
}


