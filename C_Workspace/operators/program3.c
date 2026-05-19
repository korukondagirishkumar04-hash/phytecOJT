#include<stdio.h>
int main()
{
	int num,original,remainder;
	int sum=0;
	printf("Enter a 3 digit number :");
	scanf("%d",&num);
	original=num;
	while(num!=0)
	{
		remainder=num%10;
		sum=sum+(remainder*remainder*remainder);
		num=num/10;
	}
	if(sum==original)
		printf(" given number is  Armstrong number");
	else
		printf("given number is not a Armstrong number");
	return 0;
}


