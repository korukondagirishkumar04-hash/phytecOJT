/*Write a program to display the season based on month number using ladder*/

#include<stdio.h>
int main()
{
   int month;
   printf("Enter month number (1-12): ");
    scanf("%d", &month);
   if(month == 12 || month == 1 || month == 2)
    {
        printf("Season: Winter");
    }
    else if(month >= 3 && month <= 5)
    {
        printf("Season: Summer");
    }
    else if(month >= 6 && month <= 9)
    {
        printf("Season: Rainy / Monsoon");
    }
    else if(month == 10 || month == 11)
    {
        printf("Season: Autumn");
    }
    else
    {
        printf("Invalid month number");
    }
   return 0;
}
