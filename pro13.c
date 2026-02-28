#include<stdio.h>
int main()
{
	unsigned char num;
	printf("enter the character");
	scanf("%c",&num);
	printf("before  swapping:%d\n",num);
	num=num+1;
	printf("after swapping:%d\n",num);
	return 0;
}
