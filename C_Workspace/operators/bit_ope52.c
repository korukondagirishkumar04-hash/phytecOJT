#include<stdio.h>
int main()
{
	int a;
	printf("enter the value");
	scanf(" %d",&a);
	if(!(a&1)==0){
		printf("the number is odd");
	}
	else{
		printf("the number is even");
	}
}
