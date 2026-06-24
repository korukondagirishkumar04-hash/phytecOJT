//  Program to find area and perimeter of circle.

#include <stdio.h>

int main()
{
    float r, area, perimeter;
    printf("Enter radius: ");
    scanf("%f", &r);
    area = 3.14 * r * r;
    perimeter = 2 * 3.14 * r;
    printf("Area = %.2f\n", area);
    printf("Perimeter = %.2f", perimeter);

    
}