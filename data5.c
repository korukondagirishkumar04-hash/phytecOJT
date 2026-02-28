#include<stdio.h>
#include<limits.h>
int main()
{
	printf("size of int:bytes%ld\n",sizeof(int));
	printf("size of long int:bytes%ld\n",sizeof(long int));
	printf("maximum range of int:%d\n",INT_MAX);
	printf("minimum range of  int:%d\n",INT_MIN);
	printf("maximum range of long int:%d\n", INT_MAX);
	printf("minimum range of long int:%d\n",INT_MIN);
	return 0;
}
