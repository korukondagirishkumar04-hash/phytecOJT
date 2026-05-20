#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter two integers");
	scanf("%d%d",&a,&b);
	printf("Bitwise AND (a&b) is %d\n",a&b);
	printf("Bitwise OR (a|b) is %d\n",a|b);
	printf("Bitwise XOR (a^b) is %d\n",a^b);
        printf("Bitwise NOT (~a) is %d\n",~a);
	printf("Bitwise NOT (~b) is %d\n",~b);
        return 0;
}

