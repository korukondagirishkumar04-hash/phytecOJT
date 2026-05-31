#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    char op;
    
    printf("enter the operator(p=power,%=modules,a=average,s=square):");
    scanf(" %c",&op);
    
    printf("enter the first number:");
    scanf("%d",&a);
    
    if(op != 's') 
    {
    printf("enter the second number:");
    scanf("%d",&b);
    }
     
    switch(op)
    {
        case '%':
        printf("modules:%d\n",a % b);
        break;
        
        case 'p':
        printf("power:%.1f\n",pow(a,b));
        break;
        
        case 's':
        printf("square:%d\n",a * a);
        break;
        
        
        case 'a':
        printf("average:%d\n",(a+b)/2);
        break;
        
        
        
        default:
        printf("invalid:");
        break;
    }
    
    
}