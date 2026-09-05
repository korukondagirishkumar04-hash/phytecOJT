#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter the value:");
    scanf("%d",&a);
    printf("enter the value:");
    scanf("%d",&b);
    int *x=&a;
    int *y=&b;
    *x=*x+*y;
    printf("adding of a and b:%d\n",*x);
    printf("enter the pointer:");
    scanf("%d",&c);
    
    int *z=&c;
    *z=*z+*x;
    printf("%d",*z);
    
    
}