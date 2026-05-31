#include <stdio.h>

int prime(int num)
{
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(prime(num))
    {
        printf("given number is prime");
    }
    else
    {
        printf("given number is not prime");
    }

    return 0;
}


