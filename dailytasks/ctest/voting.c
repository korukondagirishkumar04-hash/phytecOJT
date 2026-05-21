//voting eligibility
#include<stdio.h>
int main()
{
	int age;
	printf("Enter age");
	scanf("%d",&age);
	if(age>=18)
	{
		printf("You are eligible for voting");
	}
	else
	{
		printf("Your are not eligible for voting");
	}
	return 0;
}

