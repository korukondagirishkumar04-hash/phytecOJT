#include <stdio.h> 
int main() 
{ 
int year,days,weeks,remaining_days;
printf("enter the days:");
scanf("%d",&days);
year=days/365;
days=days%365;
weeks=days/7;
remaining_days=days%7;
printf("year:%d\n",year);
printf("weeks:%d\n",weeks);
printf("days:%d",days);
return 0;
}