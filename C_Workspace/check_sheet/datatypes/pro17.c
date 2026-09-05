// Program to demonstrate example of floor and ceil functions.

#include <stdio.h>
#include <math.h>

int main()
{
    float num;
    printf("Enter a number: ");
    scanf("%f", &num);
    printf("Floor = %.0f\n", floor(num));
    printf("Ceil = %.0f\n", ceil(num));
    return 0;
}