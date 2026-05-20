//Explicitly cast float to int and observe the truncation
#include<stdio.h>
int main()
{
	float num=56.7;
	int x;
	x=(int)num;
	printf("Float is %f\n",num);
	printf("Integer is %d",x);
	return 0;
}
