/* Write a program to find the largest among three numbers using if-else if-else */
#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter the number");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b && a>c){
		printf("a is largest number");
	}
	else if(b>a && b>c){
		printf("b is largest number");
	}
	else{
		printf("c is largest number");
	}
}
