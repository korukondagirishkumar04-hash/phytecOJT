#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int user,computer;
	srand(time(0));
	computer=rand()%3+1;
	printf("STONE PAPER SCISSORS GAME\n");
	printf("1.Stone\n 2.Paper\n 3.Scissors\n");
	printf("Enter your choice (1-3):");
	scanf("%d",&user);
	if(user==1)
		printf("You choose:Stone\n");
	else if(user==2)
		printf("You choose:Paper\n");
	else if(user==3)
		printf("you choose:Scissors\n");
	else
	{
		printf("Invalid Input\n");
		return 0;
	}
	if(computer==1)
		printf("Computer choose:Stone\n");
        else if(computer==2)
                printf("Computer choose:Paper\n");
        else
             printf("Computer choose:Scissors\n");
	if(user==computer)
	{
		printf("Draw!\n");
	}
	else if((user==1 && computer==3) ||
		(user==2 && computer==1) ||
		(user ==3 && computer==2))
	{
		printf("You Win\n");
	}
	else if((user==3  && computer==1)||
		(user==1 && computer==2)||
	        (user==2 && computer==3)) 
	{
		printf("Compuiter Wins!\n");
	}
	else
	{
		printf("Invalid Input!\n");
	}
	return 0;
}
