#include<stdio.h>
int main()
{
	int n,temp,sum=0,digit;
	printf("enter the value");
	scanf("%d",&n);
	temp=n;
	while(n>0)
	{
		digit=n%10;
		sum=sum+(digit*digit*digit);
		n=n/10;
	}
	if(sum==temp){
		printf("the number is armstrong");
	}
	else
	{
		printf("not armstrong");
	}
}
