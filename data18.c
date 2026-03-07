#include<stdio.h>
int main()
{
	char ch;
	printf("enter character:");
	scanf("%c",&ch);
	int result;
	result=(int)ch;
	printf("after type casting:%d\n",result);
	return 0;
}

