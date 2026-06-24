//Program to find gross salary of an employee.


#include<stdio.h>
int main()
{
    int gs,hs,da,salary;
    printf("enter the salary:");
    scanf("%d",&salary);
    
    hs=0.4*salary;
    
    da=0.2*salary;
    
    gs=hs+da+salary;
    
    printf("%d",gs);
}