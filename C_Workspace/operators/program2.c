#include<stdio.h>
int main()
{
	int num,sum=0,reminder;
	printf("Enter a number :");
	scanf("%d",&num);
	while(num!=0)
	{
		reminder=num%10;
		sum=sum+reminder;
		num=num/10;
	}
	printf("Sum of digits=%d",sum);
	return 0;
}


