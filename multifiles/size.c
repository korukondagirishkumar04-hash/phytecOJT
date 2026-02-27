#include<stdio.h>
int main()
{

	int *p1;
	float*p2;
	char*p3;
	double*p4;
	printf("Size of int pointer: %zu bytes\n", sizeof(p1));
printf("Size of float pointer: %zu bytes\n", sizeof(p2));
printf("Size of char pointer: %zu bytes\n", sizeof(p3));
printf("Size of double pointer: %zu bytes\n", sizeof(p4));
return 0;
}
