#include<stdio.h>
int main()
{
    int num;
    int even=2;
    printf("enter the num:");
    scanf("%d",&num);
    for( int i=1;i<=num;i++)
    {
        for(int j=1;j<=num-i;j++)
        {
            printf(" ");
        }
       for(int k=1;k<=i;k++)
       {
           printf("%d ",even);
           even = even + 2;
       }
       printf("\n",num);
    }
}