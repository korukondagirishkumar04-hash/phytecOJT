#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);

    int max = (a>b) ? a : b;
    printf("Maximum = %d",max);

    return 0;
}
