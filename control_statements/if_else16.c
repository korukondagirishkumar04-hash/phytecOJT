/* Write a program to check if a student passed or failed using if-else*/
#include<stdio.h>
int main()
{
	int marks;
	printf("enter marks:");
	scanf("%d",&marks);
	if(marks>=35){
		printf("student passed");
	}
	else{
		printf("stdent failed");
	}
}
