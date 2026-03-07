#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int user, computer;
    srand(time(0));
    printf("STONE PAPER SCISSORS GAME\n");
    printf("1. Stone\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("4. Quit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d",&user);
    if(user == 4)
    {
        printf("Game Quit\n");
        return 0;
    }
    if(user<1 || user>4)
    {
        printf("Invalid Input\n");
        return 0;
    }
    computer = rand()%3 + 1;
     if(user==1)
        printf("You choose: Stone\n");
    else if(user==2)
        printf("You choose: Paper\n");
    else
        printf("You choose: Scissors\n");
    if(computer==1)
        printf("Computer choose: Stone\n");
    else if(computer==2)
        printf("Computer choose: Paper\n");
    else
        printf("Computer choose: Scissors\n");
      if(user == computer)
        printf("Draw\n");
      else if((user==1 && computer==3) || 
            (user==2 && computer==1) || 
            (user==3 && computer==2))
        printf("You Win\n");
        else
        printf("Computer Wins\n");
	return 0;
}
