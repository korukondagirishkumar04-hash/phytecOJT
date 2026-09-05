//C program to print all prime numbers from 1 to N.

#include <stdio.h>

int main()
{
    int n, i, j, prime;

    printf("Enter N: ");
    scanf("%d", &n);

    for(i = 2; i <= n; i++)
    {
        prime = 1;

        for(j = 2; j <= i / 2; j++)
        {
            if(i % j == 0)
            {
                prime = 0;
                break;
            }
        }

        if(prime)
            printf("%d ", i);
    }

    return 0;
}