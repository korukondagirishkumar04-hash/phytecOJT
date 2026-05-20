/* . Write a program to display the day name based on day number (1–7) using ladder*/
#include<stdio.h>
int main()
{
	int num;
	printf("enter the number");
	scanf("%d",&num);
	if(num==1){
		printf("monday");
	}
	else if(num==2){
		printf("tuesday");
	}
	else if(num==3){
		printf("wednesday");
	}
	else if(num==4){
		printf("thursday");
	}
	else if(num==5)
	{
		printf("friday");
	}
	else if(num==6){
		printf("saturday");
	}
	else if(num==7){
		printf("sunday");
	}

	else {
		printf("invalid day number");
	}
}
