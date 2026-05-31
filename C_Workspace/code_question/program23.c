//program convert long to short and observe data loss
#include<stdio.h>
int main()
{
	long l=60000;
	short s;
	s=(short)l;
	printf("Long is %ld\n",l);
	printf("Short is %d",s);
	return 0;
}

