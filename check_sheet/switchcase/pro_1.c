// C program to read weekday number and print weekday name using switch.


#include<stdio.h>
int main()
{
    int day;
    printf("enter the weekend day(1-7): ");
    scanf("%d",&day);
    switch(day)
    {
        case 1:
        printf("Monday");
        break;
        
         case 2:
        printf("Tuesday");
        break;
        
         case 3:
        printf("Wednesday");
        break;
        
         case 4:
        printf("Thursday");
        break;
        
         case 5:
        printf("friday");
        break;
        
         case 6:
        printf("saturday");
        break;
        
         case 7:
        printf("sunday");
        break;
        
        default:
        printf("INVALID");
    }
}