/*  Write a program to check if a triangle is valid given three sides using if-else */
#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter three sides");
	scanf("%d %d %d",&a,&b,&c);
	if(a+b>c && a+c>b && b+c>a){
		printf("equal to triangle");
	}
	else{
		printf("not equal to triangle");
	}
}

