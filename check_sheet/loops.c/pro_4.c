//C Program to find sum of first N natural number, N must be taken by the user.

#include<stdio.h>
int main()
{
    int i,n,sum=0;
    printf("enter the number");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum+=i;
    }
    
    printf("sumof N natural number:%d\n",sum);
}