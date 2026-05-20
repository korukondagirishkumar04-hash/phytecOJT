//program to check if a number is even or odd using AND
#include<stdio.h>
int main()
{
	int n;
	printf("Enter a number");
	scanf("%d",&n);
	if(n&1)
		printf("Given number is Odd");
	else
		printf("Given number is Even");
	return 0;
}
