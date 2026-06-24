//salary bonus
#include<stdio.h>
int main()
{
	int salary,bonus,experience,total;
	printf("Enter Salary ");
	scanf("%d",&salary);
	printf("Enter experience");
	scanf("%d",&experience); 
	if(experience >= 25)
	{
		bonus=salary*0.05;// condition
	}
	else if(experience >=20)
	{
		bonus=salary*0.20;//condition
	}
	else if(experience > 10)
	{
		bonus=salary*0.30;
	}
	else
	{
		printf("invalid");
	}
	total =salary+bonus;
	printf("bonus amount is  %d \n",bonus);
	printf("total is %d",total);
	return 0;
}
