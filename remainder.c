#include<stdio.h>
int main()
{
	int a,b,remainder;
	printf("enter two variables");
	scanf("%d %d",&a,&b);
	remainder=a-(a/b)*b;
	printf("remainder:%d\n",remainder);
	return 0;
}
