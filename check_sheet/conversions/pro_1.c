//C program to convert number from Decimal to Binary.

#include<stdio.h>
int main()
{
    int n,binary[32],i=0;
    printf("enter the decimal number");
    scanf("%d",&n);

    while(n>0)
    {
        binary[i]=n%2;
        n=n/2;
        i++;
    }

    printf("binary=");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",binary[i]);
    }
}