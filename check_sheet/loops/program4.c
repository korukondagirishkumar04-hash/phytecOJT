/*C Program to find sum of first N natural number, N must be taken by the user.*/
#include <stdio.h>
int main()
{
    int n, i, sum = 0;
    printf("Enter Number: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        sum = sum+i;
    }
    printf("Sum = %d", sum);
    return 0;
}