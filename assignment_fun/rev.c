/*reverse a number*/
#include <stdio.h>
int reverse(int num)
{
    int rev = 0, rem;
    while(num != 0)
    {
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
    return rev;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = reverse(num);
    printf("Reversed number is %d", result);
    return 0;
}



