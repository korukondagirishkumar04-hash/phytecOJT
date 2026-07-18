//C Program to find factorial of a number.

#include<stdio.h>
int main()
{
    int i,num;
    int fact=1;
    printf("enter the number ");
    scanf("%d",&num);
    
    for(i=1;i<=num;i++)
    {
        fact*=i;
    }
    printf("factorial number:%d\n",fact);
}