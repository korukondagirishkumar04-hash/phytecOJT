#include<stdio.h>
int main()
{
	float celsius,fahrenheit;
	printf("celsius temperature:");
	scanf("%f",&celsius);
	fahrenheit=(celsius* 9/5)+32;
	printf("temperature fahrenheit:%f\n",fahrenheit);
	return 0;
}
