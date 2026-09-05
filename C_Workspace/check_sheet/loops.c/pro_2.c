//C Program to check entered number is ZERO, POSITIVE or NEGATIVE until user does not want to quit.

#include<stdio.h>
int main()
{
    int num;
    char choice;
    
    do
    {
       printf("enter the number:");
    scanf("%d",&num); 
    
    if(num>0)
    {
        printf("positive number\n");
    }
    else if(num<0)
    {
        printf("negative number\n");
    }
    else
    {
        printf("zero\n");
    }
    printf("where you want to continue(y/n)");
    scanf(" %c",&choice);
    }
    while(choice=='y'|| choice=='Y');
    return 0;
}