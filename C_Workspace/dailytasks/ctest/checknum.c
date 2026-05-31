//check even,odd,digit,divisible
#include<stdio.h>
int main()
{
	int n;
	printf("Enter number n ");
	scanf("%d",&n);
	//check even or odd
	if(n%2==0)
	{
		printf("given nummber is even\n");
	}
	else
	{
		printf("given number is odd\n");
	}
	//check positive or negative
	if(n<0)
	{
		printf("given number is negative\n");
	}
	else
	{
		printf("given number is positive\n");
	}
	//divisibility 2,3,5
	if(n % 2==0 && n % 3==0 && n % 5==0)
	{
		printf("given number is divisible by 2,3,5\n");
	}
	else
	{
		printf("given number is not diviisible\n");
	}
	//digit count
	if(n>=0 && n<= 9)
	{
		printf("single digit\n");
	}
	else if(n>=10 && n<100)
	{
		printf("double digit");
	}
	else
	{
		printf("multi digit");
	}

	return 0;
}

