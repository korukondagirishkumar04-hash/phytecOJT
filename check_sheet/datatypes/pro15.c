// Program to multiply two numbers using plus operator.

#include <stdio.h>
int main()
{
    int a, b, result = 0;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    for(int i = 0; i < b; i++)
    {
        result = result + a;
    }
    printf("Multiplication = %d", result);
    return 0;
}