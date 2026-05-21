/* Write a program to check if a character is a digit or not using if-else */
#include<stdio.h>
int main()
{
	char ch;
	printf("enter the character");
	scanf("%c",&ch);
	if(ch>='0' && ch<='9'){
		printf("it is digit:");
	}
	else{
		printf("it is not a digit:");
	}
}
