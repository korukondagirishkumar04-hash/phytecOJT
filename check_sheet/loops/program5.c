//print prime num 1 to n
#include<stdio.h>
int main()
{
    int n, i, j, count;

    printf("Enter N: ");
    scanf("%d", &n);

    for(i = 2; i <= n; i++)
    {
        count = 0;

        for(j = 2; j <= i/2; j++)
        {
            if(i % j == 0)
            {
                count++;
                break;
            }
        }

        if(count == 0)
        {
            printf("%d ", i);
        }
    }

    return 0;
}