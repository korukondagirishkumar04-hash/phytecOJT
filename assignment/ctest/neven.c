//n even numbers
#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter number of elements");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("even numbers are %d  \n",2*i);//to print even numbers
	}
	return 0;
}
