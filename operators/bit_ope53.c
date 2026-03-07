#include<stdio.h>
int main()
{
	int a,b;
	printf("enter two values");
	scanf("%d %d",&a,&b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("swap values:%d\n,%d\n",a,b);
	return 0;
}
