#include<stdio.h>
int main()
{
	int a=9;
	int i,j;
	for(  i=7;i>=0;i--)
	{
	j=(a>>i)&0x01;
	printf("%d",j);
	}
	return 0;
}
