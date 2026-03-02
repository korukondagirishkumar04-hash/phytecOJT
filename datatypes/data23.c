#include<stdio.h>
int main()
{
	long l=233;
	short s=(long) l;
	printf("integer value:%ld",l);
	printf("casting:%d",s);
	return 0;
}
