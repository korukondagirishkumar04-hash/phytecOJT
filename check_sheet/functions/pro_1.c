//1) C program to find SUM and AVERAGE of two integer Numbers using User Define Function

#include<stdio.h>
int sum(int a,int b)
{
    int sum;
    sum=a+b;
    
}
int average(int a, int b)
{
    int average;
    average=a+b/2;
}
int main()
{
    int x,y;
    printf("enter the values:");
    scanf("%d %d",&x,&y);
    printf("sum:%d\n",sum(x,y));
    printf("average:%d",average(x,y)/2);
}