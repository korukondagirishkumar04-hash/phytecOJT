//Demonstrate short int and size and its memory size
#include<stdio.h>
int main()
{
	short int s=100;
	printf("Short int value is%d\n",s);
	printf("Size is %lu bytes\n",sizeof(short int));
	return 0;
}
