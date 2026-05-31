#include<stdio.h>

void palindrome(int num)
{
    int temp,orginal,rev=0;
    orginal=num;
    while(num!=0)
    {
        temp=num%10;
        rev=rev*10+temp;
        num=num/10;
    }
    if(orginal==num)
    {
        printf("palindrome number");
    }
    else
    {
        printf("not palindrome");
    }
    
}
int main()
{
    int num;
    printf("enter the number:");
    scanf("%d",&num);
    palindrome(num);
    return 0;
    
}
