#include<stdio.h>
void fabonic(int num)
{
  int a=0,b=1,c;
  for(int i=0;i<num;i++)
  {
      printf("%d\n",a);
    c=a+b;
    a=b;
    b=c;
  }
    
    
}
int main()
{
    int num;
    printf("enter the number:");
    scanf("%d\n",&num);
    fabonic(num);
    return 0;
    
    
    
}