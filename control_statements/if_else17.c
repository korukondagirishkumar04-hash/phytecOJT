/* Write a program to check if a number is divisible by 3 or not using if-else*/
#include<stdio.h>
int main()
{
	int num;
	printf("enter the value");
	scanf("%d",&num);
	if(num%3==0){
		printf("divisible number");
	}
	else{
		printf("not divisible");
	}
}
