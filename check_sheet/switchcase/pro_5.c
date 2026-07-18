// C program to check whether number is EVEN or ODD using switch.

#include<stdio.h>
int main()
{
    int num;
    printf("enter the number:");
    scanf("%d",&num);
    
    switch(num%2)
    {
        case 0:
        printf("even number");
        break;
        
        case 1:
        case -1:
        printf("odd number");
        break;
        
        default:
        printf("invalid number");
        
    }
}