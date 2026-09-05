/*Write a program to classify a triangle as Equilateral, Isosceles, or Scalene using ladder */


#include<stdio.h>
int main()
{
    int a, b, c;
   printf("Enter three sides of triangle: ");
    scanf("%d %d %d", &a, &b, &c);
    if(a == b && b == c)
    {
        printf("Triangle is Equilateral");
    }
    else if(a == b || b == c || a == c)
    {
        printf("Triangle is Isosceles");
    }
    else
    {
        printf("Triangle is Scalene");
    }
   return 0;
}
