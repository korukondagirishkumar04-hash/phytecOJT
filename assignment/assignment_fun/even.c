#include <stdio.h>
int iseven(int num)
{
    if(num%2==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int num;
    printf("Enter a number");
    scanf("%d",&num);
    if(iseven)
    {
        printf("given number is even");
    }
    else
    {
        printf("given number is odd");
    }
}

