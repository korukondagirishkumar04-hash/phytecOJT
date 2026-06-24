// Program to find area of a rectangle.

#include <stdio.h>
int main()
{
    float l, b, area;
    printf("Enter length and breadth: ");
    scanf("%f%f", &l, &b);
    area = l * b;
    printf("Area = %.2f", area);
    return 0;
}