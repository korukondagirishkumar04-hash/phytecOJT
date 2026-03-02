#include<stdio.h>
#include<limits.h>
int main()
{
	int num=INT_MAX;
	printf("maximum int value:%d\n",num);
	num =num+1;
	printf("overflow value:%d\n",num);
	return 0;
}
