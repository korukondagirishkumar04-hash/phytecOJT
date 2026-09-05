//Program to calculate X^N (X to the power of N) using pow function.


#include<stdio.h>
#include<math.h>

int main()
{
    int base,expo;

    printf("Enter base and expo: ");
    scanf("%d%d",&base,&expo);

    printf("Result = %.0f",pow(base,expo));

    return 0;
}