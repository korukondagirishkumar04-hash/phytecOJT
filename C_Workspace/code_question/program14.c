//Print ASCII values A TO Z
#include<stdio.h>
int main()
{
	char ch;
	for(ch='A';ch <='Z';ch++)
	{
		printf("%c is %d\n",ch,ch);
	}
	return 0;
}
