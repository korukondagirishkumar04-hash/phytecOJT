#include<stdio.h>
#include<math.h>
int main()
{ 
	float p,r,t,ci,amount;
	printf("the principal amount");
	scanf("%f",&p);
	printf("enter rate of interest");
	scanf("%f",&r);
	printf("enter duration ");
	scanf("%f",&t);
	amount=p*pow((1+r/100),t);
	ci=amount-p;
	printf("amount:%.2f",amount);
	printf("ci:%.2f",ci);
}



