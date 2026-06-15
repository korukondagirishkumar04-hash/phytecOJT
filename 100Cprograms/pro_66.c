#include<stdio.h>
int add(int a,int b)
{
int c;
c=a+b;
return c;
}
int main(int a,int b)
{
    int sum;
printf("enter two numbers:");
scanf("%d %d",&a,&b);

sum=add(a,b);
printf("%d",sum);
return 0;

}