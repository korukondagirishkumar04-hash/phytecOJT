#include<stdio.h>
int main()
{
	int num,a=0,b=1,next;
	printf("enter the variable range");
	scanf("%d",&num);
	printf("fibbnocci");
	for(int i=1;i<=num;i++)
	{

		printf("%d",a);
	        next=a+b;
		a=b;
		b=next;
	}
}



