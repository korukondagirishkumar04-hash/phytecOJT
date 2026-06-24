//C program to convert number from Decimal to Hexadecimal.

#include<stdio.h>
int main()
{
    int n,i=0,rem;
    char hex[20];

    printf("enter the decimal:");
    scanf("%d",&n);

    while(n!=0)
    {
        rem=n%16;
        if(rem<10)
        {
            hex[i]=rem+48;
        }
        else{
            hex[i]=rem+55;
        }
        n=n/16;
        i++;

        
    }

    printf("hexadecimal number:");
    for(i=i-1;i>=0;i--)
    {
        printf("%c",hex[i]);
    }
}