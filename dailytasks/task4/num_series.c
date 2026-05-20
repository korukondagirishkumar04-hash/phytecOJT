#include<stdio.h>
int main()
{
	int n,sum=0,term,i;
	printf("Enter the number n ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		term=1+(i*10);
		sum=sum+term;
	}
	printf("Series of the number is %d",sum);
	return 0;
}

