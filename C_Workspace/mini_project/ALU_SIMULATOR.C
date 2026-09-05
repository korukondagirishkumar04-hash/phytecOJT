// Do not use * for multiplication.
//Do not use / for division.
//Implement multiplication using repeated addition (+).
//Implement division using repeated subtraction (-).

#include<stdio.h>
int main()
{
    int a,b,choice;
    int result=0,quotient=0;
    
    printf("-----4 BIT ALU------ \n");
    printf("--------------------\n");
    
    printf("please enter the number between 0 to 15\n");
    printf("enter the first number:\n");
    scanf("%d",&a);
    
    printf("enter the second number:\n");
    scanf("%d",&b);
    
    if(a<0 || a>15 || b<0 || b>15)
    {
        printf("invalid numbers\n");
    }
    
     printf("-------------------------------\n");
    printf("operators\n");
    printf("\t\t\t1.ADDITION\n");
    printf("\t\t\t2.SUBSTRACTION\n");
    printf("\t\t\t3.MULTIPLICATION\n");
    printf("\t\t\t4.DIVISION\n");
     printf("-----------------------\n");
    printf("select the operator\n");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
        printf("Addition :%d\n",a+b);
        break;
        
        case 2:
        printf("substraction:%d\n",a-b);
        break;
        
        case 3:
        for(int i=0;i<b;i++)
        {
            result=result+a;
        }
        printf("multiplication:%d\n",result);
        
        break;
        
        case 4:
        if(a>=b)
        {
            a=a-b;
            quotient++;
        }
        printf("QUOTIENT:%d\n",quotient);
        printf("REMAINDER:%d\n",a);
        
        default:
        printf("-------INVALID NUMBER-----");
    }
    
    
    return 0;
    
}