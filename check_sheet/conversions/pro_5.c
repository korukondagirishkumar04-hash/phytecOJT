//C program to convert number from Octal to Decimal.


#include<stdio.h>
#include<math.h>

int main()
{
    int octal, decimal = 0;
    int rem, i = 0;

    printf("Enter octal number: ");
    scanf("%d", &octal);

    while(octal != 0)
    {
        rem = octal % 10;
        decimal += rem * pow(8, i);
        octal /= 10;
        i++;
    }

    printf("Decimal = %d", decimal);

    return 0;
}