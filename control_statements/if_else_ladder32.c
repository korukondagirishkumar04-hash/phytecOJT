/*  Write a program to find if a number is divisible by 2, 3, 5, or none using ladder*/

#include<stdio.h>
int main()
{
    int num;
  printf("Enter a number: ");
    scanf("%d", &num);
    if(num % 2 == 0)
    {
        printf("The number is divisible by 2");
    }
    else if(num % 3 == 0)
    {
        printf("The number is divisible by 3");
    }
    else if(num % 5 == 0)
    {
        printf("The number is divisible by 5");
    }
    else
    {
        printf("The number is not divisible by 2, 3, or 5");
    }

    return 0;
}
