#include<stdio.h>
int main()
{
	double radius,area;
	double pi=3.14159;
	printf("Enter radius of circle:");
	scanf("%lf",&radius);
	area=pi*radius*radius;
	printf("Area of circle is %2lf",area);
	return 0;
}
