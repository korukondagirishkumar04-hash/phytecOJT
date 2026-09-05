#include<stdio.h>
int main()
{
    int num;
 printf("Enter a number: ");
    scanf("%d", &num);
    if(num < 1 || num > 100)
        printf("Number is outside the range\n");
    else
        printf("Number is inside the range\n");
 return 0;
}
