/*write a program to check if a number is postive or negative using if else*/
#include<stdio.h>
int main()
	{
		int num;
		printf("enter the value:");
		scanf("%d",&num);
		if(num>=0){
			printf("positive");
		}
		else {
			printf("negative");
		}
		return 0;
	}
