/* Write a program to check if a number is inside or outside the range 1–100 using if else*/
#include<stdio.h>
int main()
{
	int num;
	printf("enter the number");
	scanf("%d",&num);
	if(num>1 && num<100){
		printf("given number is inside the range");
	}
	else{
		printf("given number is out side the range");
	}
}
