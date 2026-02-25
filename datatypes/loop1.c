#include<stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);

    if(num >= 0)
        printf("Positive number");
    if(num < 0)
        printf("Negative number");

    return 0;
}
