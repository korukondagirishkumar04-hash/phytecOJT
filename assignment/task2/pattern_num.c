#include<stdio.h>
int main()
{
	int num,i,j,count=1;
	printf("Enter a number");
	scanf("%d",&num);
	for(i=1;count<=num;i++)
	{
		for(j=1;j<=i && count<=num;j++)
		{
			printf("%d",count);
			count++;
		}
		printf("\n");
	}
	return 0;
}

