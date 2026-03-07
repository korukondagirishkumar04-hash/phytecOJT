#include<stdio.h>
int main()
{
	int year;
	printf("enter the year");
	scanf("%d",&year);
	if((year %4==0 && year%100!=0)||(year==100)){
		printf("leap year");
	}
	else{
		printf("not a leap year");
	}
}
