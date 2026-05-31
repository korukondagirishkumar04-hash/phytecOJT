/*max number*/
#include<stdio.h>
int max(int a,int b,int c)
{
    if((a>b)&&(a>c))
    {
        printf("a is greater");
    }
    else if((b>a)&&(b>c))
    {
        printf("b is greter");
    }
    else
    {
        printf("c is greater");
    }
}
int main()
{
   int a,b,c;
   printf("Enter a,b,c");
   scanf("%d%d%d",&a,&b,&c); 
    max(a,b,c);
   return 0;
}


