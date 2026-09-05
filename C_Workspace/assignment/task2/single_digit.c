#include<stdio.h>
int main()
{
	int num,sum=0,digit;
	printf("Enter number");
	scanf("%d",&num);
	while(num>9)
	{
		sum=0;
	while(num!=0)
	{
		digit = num%10;
		sum= digit+sum;
		num=num/10;
	}
	num=sum;
	}
	printf("Single digit is %d",num);
	return 0;
}

