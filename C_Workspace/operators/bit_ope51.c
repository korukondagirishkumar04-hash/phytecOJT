#include<stdio.h>
int main()
{
	int num;
	int result;
	printf("enter the value");
	scanf("%d",&num);
	result=num>>9;
	printf("bitwise rightshift:%d\n",result);
	return 0;
}
