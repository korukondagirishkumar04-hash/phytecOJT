#include<stdio.h>
int main()
{
    int num;
    printf("enter the number:");
    scanf("%d",&num);
    switch(num)
    {
        case 1:
        printf("a@");
        break;
        
        case 2:
        printf("b#");
        break;
        
        case 3:
        printf("c+");
        break;
        
        case 4:
        printf("d-");
        break;
        
        case 5:
        printf("f/");
        break;
    }
    
}