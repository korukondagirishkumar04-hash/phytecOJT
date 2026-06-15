#include<stdio.h>
#include<math.h>
int power(int base,int exp)
{
    int i,result=1;
    for(i=1;i<=exp;i++)
    {
        result=result*base;
    }
    return result;
    
}
int main()
{
    
    int a,b,result;
    printf("enter the base:");
    scanf("%d",&a);
    
    printf("enter the exp:");
    scanf("%d",&b);
    
    result=power(a,b);
    printf("%d",result);
    return 0;
}