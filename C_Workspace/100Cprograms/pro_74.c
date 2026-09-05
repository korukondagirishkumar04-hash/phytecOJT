#include<stdio.h>
int sumofdigit(int num)
{
    int digit,sum=0;
    if(num!=0)
    {
        digit=num%10;
        sum=sum+digit;
        num=num/10;
    }
    return sum;
    
}
int main()
{
    int n,sum;
    printf("enter the number:");
    scanf("%d",&n);
    sum=sumofdigit(n);
    printf("%d",sum);
    
}