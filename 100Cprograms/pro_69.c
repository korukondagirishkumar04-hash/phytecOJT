#include<stdio.h>
int  fab(int num)
{
    int a=0,b=1,c,i;
    if(num<=0)
    {
        printf("enter only positive numbers:\n");
    }
    printf("fabonacci series:");
    if(num>=1)
    {
     printf("%d",a);   
    }
    if(num>=2)
    {
        printf("%d",b);
    }
    for(i=3;i<=num;i++)
    {
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
    }
    
}

int main()
{
  int n;
  printf("enter the number:");
  scanf("%d",&n);
  printf("%d",fab(n));
  return 0;
    
    
}