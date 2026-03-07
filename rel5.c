#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter the values");
	scanf("%d %d %d",&a,&b,&c);
	if(a > b && a > c)
		printf("a is largest number");
	else if(b > c)
		printf("b is largest number");
	else
	printf("c is largest number");
}
