#include<stdio.h>
int main()
{
	int n,i,count=0,sum=0;
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			count++;
			sum=sum+i;
		}
	}  
	printf("The sum of divisors %d",sum);
	printf("The count of divisors %d",count);
	return 0;
}
