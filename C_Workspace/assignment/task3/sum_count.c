#include<stdio.h>
int main()
{
	int num,sum=0,count=0,digit;
	printf("Enter number");
	scanf("%d",&num);
	while(num!=0)
	{
		digit = num%10;
		sum= digit+sum;
		count++;
		num=num/10;
	}
	printf("Sum of given number is %d",sum);
	printf("\nnumber of the digit is %d",count);
	return 0;
}
