#include<stdio.h>
int main()
{
	int a,b,result;
	printf("enter the values");
	scanf("%d %d",&a,&b);
	result=a&b;
	printf("bitwise result:%d\n",result);
	return 0;
}
