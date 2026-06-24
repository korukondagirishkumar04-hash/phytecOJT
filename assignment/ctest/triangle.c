//triangle validation
#include<stdio.h>
int main()
{
	int a,b,c,triangle;
	printf("Enter a,b,c ");
	scanf("%d%d%d", &a,&b,&c);
	triangle=a+b+c;//adding values and assigning
	if(triangle=180)//triangle validation check
	{
		printf("It is a valid triangle");
	}
	else
	{
		printf("It is not a valid triangle");
	}
	return 0;
}
