#include<stdio.h>
int main()
{
	int n,digit, original,reverse=0;
	printf("Enter a number n ");
	scanf("%d",&n);
	original=n;
	while(n!=0)
	{
		digit=n%10;
		reverse=reverse*10+digit;
		n=n/10;
	}
	printf("original number is %d\n",original);
	printf("reversed number id %d\n",reverse);
	if(reverse==n)
	{
		printf("Both are equal");
	}
	else if(reverse > n)
	{
		printf("reverse is greater than n");
	}
	else
	{
		printf("reverse is smaller than n");
	}
	return 0;
}

