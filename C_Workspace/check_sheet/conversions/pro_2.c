//C program to convert number from Decimal to Octal.

#include<stdio.h>
int main()
{
    int n,octal[32],i=0;
    printf("enter the decimal:");
    scanf("%d",&n);
    
    while(n>0)
    {
        octal[i]=n%8;
        n=n/8;
        i++;
    }
    
    printf("octal:");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",octal[i]);
    }
}