#include<stdio.h>

union data{
	int i;

float f;
char c;
};
int main()
{
	union data f;
	f.i=65;
	printf("as int:%d\n",f.i);
	printf("as char:%d\n",f.c);
	return 0;
}
