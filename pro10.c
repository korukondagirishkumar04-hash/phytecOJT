#include <stdio.h>
int main()
{
double r, area;
double pi = 3.1416;
printf("Enter radius: ");
scanf("%lf", &r);
area = pi * r * r;
printf("Area of circle = %.4lf\n", area);
return 0;
}

