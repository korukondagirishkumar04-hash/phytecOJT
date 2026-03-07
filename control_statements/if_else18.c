/*  Write a program to check if a year is a leap year or not using if-else */
#include<stdio.h>
int main()
{
	int year;
	printf("enter the year");
	scanf("%d",&year);
	if(year%4==0 && year%100!=0  || year%400==0){
		printf("it is a leap year");
	}
	else{
		printf("it is not leap year");
	}
}

