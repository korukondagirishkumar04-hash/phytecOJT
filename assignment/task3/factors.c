#include<stdio.h>
int main()
{
	int n,i,count=0;
	printf("Enter a number n ");
	scanf("%d",&n);
	printf("Factors of numbers  %d are",n);
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			printf(" %d",i);
		count++;
		}

	}
	printf("\nTotal number of factors are %d",count);
	return 0;
}
