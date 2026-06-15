#include<stdio.h>

int reverse(int num)
{
    int rev = 0, r;

    while(num != 0)
    {
        r = num % 10;
        rev = rev * 10 + r;
        num = num / 10;
    }

    return rev;
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reversed Number = %d\n", reverse(num));

    return 0;
}