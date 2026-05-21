/* Write a program to calculate electricity bill based on units consumed using ladder 0–100 units → ₹1.5/unit, 101–300 → ₹2.5/unit, above 300 → ₹4/unit */

#include<stdio.h>
int main()
{
    int units;
    float bill;
   printf("Enter the number of units consumed: ");
    scanf("%d", &units);
   if(units <= 100)
    {
        bill = units * 1.5;
    }
    else if(units <= 300)
    {
        bill = units * 2.5;
    }
    else
    {
        bill = units * 4;
    }
    printf("Electricity Bill = Rs %.2f\n", bill);
     return 0;
}
