#include<stdio.h>

int gcd(int a,int b)
{
    int temp;
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
    
    
    
}
int main()
{
   int x,y,result;
   printf("enter the numbers:");
   scanf("%d %d",&x,&y);
   
   result=gcd(x,y);
    printf("%d\n",result);
}