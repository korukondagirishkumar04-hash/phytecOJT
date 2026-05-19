//size of int,float,double,char using sizeof()
#include<stdio.h>
int main()
{
	int var;
	printf("size of int is %lu bytes\n",sizeof(int));
	printf("size of float is %lu bytes\n",sizeof(float));
	printf("size of double is %lu bytes\n",sizeof(double));
	printf("size of char is %lu bytes\n",sizeof(char));
	return 0;
}
