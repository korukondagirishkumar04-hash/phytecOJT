#include<stdio.h>
int main()
{
    int a;
    printf("enter the variables:");
    scanf(" %d",&a);
    int *x=&a;
    if((*x)%2==0)
    {
        printf("even:");
    }
    else
    {
        printf("odd");
    }
}