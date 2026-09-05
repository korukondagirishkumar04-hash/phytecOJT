// C program to design calculator with basic operations using switch.

#include<stdio.h>
int main()
{
    int a,b;
    char op;
    
    printf("enter the first number:");
    scanf("%d",&a);
    
    printf("enter the operators(+,-,*,/):\n");
    scanf(" %c",&op);
    
    printf("enter the second number:");
    scanf("%d",&b);
    
    
    switch(op)
    {
        case '+':
        printf("result:%d",a+b);
        break;
        case '-':
        printf("result:%d",a-b);
        break;
        case '*':
        printf("result:%d",a*b);
        break;
        case '/':
        printf("result:%d",a/b);
        break;
        
        default:
        printf("invalid operation");
        
    }
}