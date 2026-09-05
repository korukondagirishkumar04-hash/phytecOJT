#include<stdio.h>
int main()
{
    int year;
    printf("Enter year: ");
    scanf("%d",&year);
    if(year % 4 == 0)
    {
        printf("Year is divisible by 4");
    }
   return 0;
}
