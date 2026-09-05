//C program to convert number from Binary to Decimal.

#include<stdio.h>
#include<math.h>
int main()
{
    int n,i=0,decimal=0,rem;
    printf("enter the binary:");
    scanf("%d",&n);
    
    while(n!=0)
    {
        rem=n%10;
        decimal+= rem * pow(2,i);
        n=n/10;
        i++;
    }
    printf("decimal:");
    printf("%d",decimal);
    
    return 0;
}