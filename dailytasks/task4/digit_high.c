#include<stdio.h>
int main()
{
	int n,max_digit,digit;
	printf("Enter a number n ");
	scanf("%d",&n);
	if(n==0)
	{
		printf("The highest number is %d",n);
	}
	while(n>0)
	{
		digit=n%10;
		if(digit>max_digit)
		{
			max_digit=digit;
		}
		n=n/10;
	}
	printf("Highest number is %d",max_digit);
	return 0;
}
