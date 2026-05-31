#include<stdio.h>
#include<math.h>
int main()
{
    int base,exp,dummy;
    printf("enter the number:");
    scanf("%d",&base);
    printf("enter the exp:");
    scanf("%d",&exp);
    dummy=pow(base,exp);
    printf("%d\n",dummy);
    return 0;
}