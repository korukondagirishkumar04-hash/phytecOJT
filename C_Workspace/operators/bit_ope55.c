#include<stdio.h>
int main()
{
	int num=19;
	int pos=33;
	num=num &~(1<<pos);
		printf("specified bits:%d\n",num);
	return 0;
}
