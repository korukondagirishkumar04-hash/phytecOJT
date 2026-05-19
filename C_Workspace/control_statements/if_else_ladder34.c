/* . Write a program to calculate income tax using salary slabs using ladder*/


#include<stdio.h>
int main()
{
	float salary,tax;
	printf("enter salary:");
	scanf("%f",&salary);
	if(salary<=250000){
		tax=0;
	}
	else if(salary<=500000){
		tax=salary*0.05;
	}
	else if(salary<=1000000){
		tax=salary*0.20;
	}
	else{
		tax=salary*0.30;
	}
	printf("income tax:%f",tax);
}
