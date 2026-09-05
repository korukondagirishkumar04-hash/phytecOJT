#include<stdio.h>
int main()
{
	int a,b;
	printf("enter two variables");
	scanf("%d,%d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("after swapping:%d,%d",a,b);
	return 0;
}
