//Program to Declare, Initialize Union

#include<stdio.h>
union bank
{
    int account;
    char name[34];
    float cash;
};
int main()
{
    union bank s;
    
    printf("enter your account no:");
    scanf("%d",&s.account);
    printf("enter your name:");
    scanf("%s",s.name);
    printf("enter your cash:");
    scanf("%f",&s.cash);
    
    printf("details\n");
    printf("account no:%d\n",s.account);
    printf("name:%s\n",s.name);
    printf("cash:%2.f\n",s.cash);
    
    
}