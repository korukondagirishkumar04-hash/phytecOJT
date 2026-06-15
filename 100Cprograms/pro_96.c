//. Write a C program to swap two numbers using pointers


#include<stdio.h>
int main()
{

    int a,b,temp;
    int *p,*q;
    p=&a;
    q=&b;
    printf("enter two number:");
    scanf("%d %d",&a,&b);

    temp=*p;
    *p=*q;
    *q=temp;

    printf("%d",a);
    printf("%d",b);
    return 0;
}