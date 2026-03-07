#include<stdio.h>
int main()
{
	int a=34;
	a&=34;
	printf("after:%d\n",a);
	a|=34;
	printf("after:%d\n",a);
	a^=34;
	printf("after:%d\n",a);
	return 0;
}
