#include<stdio.h>
int main()
{
	int a;
	printf("enter the value");
	scanf("%d",&a);
	if(a>18){
		printf("eligible for right to vote");
	}
	else{
		printf("not eligible");
	}
	return 0;
}
