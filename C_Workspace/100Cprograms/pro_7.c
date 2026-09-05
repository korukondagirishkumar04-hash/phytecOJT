// 7 .Write a program to Read the radius of a circle Calculate the area using the formula:Area = π × r × r  and Display the area?

#include<stdio.h>

int main()
{
    float r, area;

    printf("Enter the radius of circle: ");
    scanf("%f", &r);

    area = 3.14 * r * r;

    printf("Area of circle = %.2f", area);
    return 0;
}