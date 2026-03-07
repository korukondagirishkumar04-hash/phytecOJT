#include<stdio.h>
int main()
{
        int a,b,max;
       printf("Enter the values: ");
        scanf("%d %d",&a,&b);
        max = (a>b) ? a : b;
	printf("Max: %d\n", max);
        return 0;
}
