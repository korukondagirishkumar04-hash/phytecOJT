#include<stdio.h>
int main()
{
    int salary ,a,b,a1,b1;
    printf("enter your salary:");
    scanf("%d",&salary);
    a=(salary*15)/100;
    a1=salary+a;
    printf("after increse of salary:%d\n",a1);
    b=(salary*5)/100;
    b1=salary-b;
    printf("after decrease:%d\n",b1);
    return 0;
    
    
    
}