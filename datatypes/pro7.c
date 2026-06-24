//Program to convert temperature from Fahrenheit to Celsius and vice versa.


#include<stdio.h>
int main()
{
    int f,c;
    printf("temperature in celsius and fahrenhiet:");
    scanf("%d %d",&c,&f);
    c=(f-32)*5/9;
    f=(c*9/5)+32;
    printf("temperature in celsius:%d\n",c);
    printf("temperature in fahrenhiet:%d\n",f);
}