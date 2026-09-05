#include<stdio.h>
int main()
{
	int rows,num=2,i,j;
	printf("Enter number of rows ");
	scanf("%d",&rows);
	for(i=1;i<=rows;i++)
	{
		for(j=1;j<=rows-i;j++)
		{
		printf(" ");
		}
		for(j=1;j<=i;j++)
		{
			printf("%d ",num);
			num=num+2;
		}
		printf("\n");
	}
	return 0;
}


