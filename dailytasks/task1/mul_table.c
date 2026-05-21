#include<stdio.h>
int main()
{
	int num,i;
	printf("Enter the number");
	scanf("%d",&num);
	for(i=0;i<=12;i++)
	{
		printf("%d*%d=%d\n",num,i,num*i);
	}
	return 0;
}
