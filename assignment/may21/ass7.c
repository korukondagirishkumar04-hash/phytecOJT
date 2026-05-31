#include<stdio.h>
int main()
{
    int a;
    printf("enter the number:");
    scanf("%d",&a);
    int *x=&a;
    printf("square:%d",(*x) * (*x));
    
}