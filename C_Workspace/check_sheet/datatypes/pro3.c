//Program to calculate simple interest.

#include<stdio.h>
int main()
{
    int p,r,t,si;
    printf("enter the principle:");
    scanf("%d",&p);
    printf("enter the rate:");
    scanf("%d",&r);
    printf("enter the time:");
    scanf("%d",&t);

    si=(p*t*r)/100;

    printf("%d",si);
}