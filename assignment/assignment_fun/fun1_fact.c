#include<stdio.h>
int fact(int num)
{
    int fact=1;
    for(int i=1;i<=num;i++)
    {
        fact*=i;
    }
    return fact;

    
}
int main()
{
    int num;

    printf("enter the number:");
    scanf("%d",&num);
   
    printf("fact:%d",fact(num));
 return 0;   
}