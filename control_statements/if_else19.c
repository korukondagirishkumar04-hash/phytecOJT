/*  Write a program to check if a number is single digit or multi digit using if-else*/

#include<stdio.h>
int main()
{
	int num;
	printf("enter the number");
	scanf("%d",&num);
	if(num>=0 && num<=9)
	{
		printf("single digit number");
	}
	else
	{
		printf("multi digit");
	}
	return 0;}

