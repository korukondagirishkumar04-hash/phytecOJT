#include<stdio.h>
int main()
{
	int n,first,last,sum;
	printf("Enter a number n ");
	scanf("%d",&n);
	last=n%10;
	while(n>=10)
	{
		n=n/10;
	}
	first=n;
	sum=last+first;
	printf("sum is %d",sum);
	return 0;
}
