//C Program to print tables from numbers 1 to 20.

#include<stdio.h>
int main()
{
    int i,j;
    
    for(i=1;i<=20;i++)
    {
        printf("\ntables:%d\n",i);
    
    for(j=1;j<=10;j++)
    {
        printf("%dx%d=%d\n",i,j,i*j);
    }
    }
    return 0;
}