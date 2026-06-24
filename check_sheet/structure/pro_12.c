//Program to Demonstrate Structure Array


#include<stdio.h>
struct work{
    int roll;
    char name[45];
};
int main()
{
    struct work s;
    for (int i=0;i<2;i++)
    {
     printf("enter your hours and suject:");
     scanf("%d %s",&s.roll,&s.name);
    }
    
    printf("details:");
    for(int i=0;i<2;i++)
    {
        printf(" roll:name\n:%d%s",s.roll,s.name);
        
    }
    return 0;
}