#include<stdio.h>
int main()
{
    int a=12,b=34,c=32,d;
    int *x=&c;
    *x=d;
    printf("enter the number:");
    scanf("%d",&d);
      
    printf("after change:%d %d %d",a,b,d);

}