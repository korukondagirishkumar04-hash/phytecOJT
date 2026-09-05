#include<stdio.h>
int main()
{
    int a,b,c ,avg;
    printf("enter the three numbers:");
    scanf("%d %d %d",&a,&b,&c);
    
    avg=(a+b+c)/3;
    printf("average:%d\n",avg);
    return 0;
    
}