/*program to check whether the number is even or odd*/


#include<stdio.h>
int main()
{
	int num;
	printf("enter the value:");
	scanf("%d",&num);
	if(num%2==0){
		printf("number is even");
	}
	else{
		printf("number is odd");
	}
}
