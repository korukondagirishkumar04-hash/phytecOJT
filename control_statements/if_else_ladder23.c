/* Write a program to print grade based on marks using if-else if-else ladder Marks >= 90 → A, >= 80 → B, >= 70 → C, >= 60 → D, else → F */
#include<stdio.h>
int main()
{
	int marks;
	printf("enter the marks");
	scanf("%d",&marks);
	if(marks>=90){
		printf("student got A grade");
	}
	else if(marks>=80){
		printf("student got B grade");
	}
	else if(marks>=70){
		printf("student got C");
	}
	else if(marks>=60){
		printf("student got D");
	}
	else{
		printf("student failed");
	}
	return 0;
}
