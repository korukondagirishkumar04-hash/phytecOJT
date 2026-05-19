#include<stdio.h>
int main()
{
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	if(num&1)
		printf("The number is odd.\n");
	else
		printf("The number is even.\n");
	return 0;
}
