#include<stdio.h>
int main()
{
    int a,b;
    printf("enter the number:");
    scanf("%d %d",&a,&b);
    a=a^b;
    b=b^a;
    a=a^b;
    printf("swap:%d %d\n",a,b);
    return 0;
}