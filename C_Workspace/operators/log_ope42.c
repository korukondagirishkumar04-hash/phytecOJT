#include<stdio.h>
int main()
{
    int num;
 printf("Enter a number: ");
    scanf("%d", &num);

    if(!(num > 0))
        printf("Number is not positive\n");
    else
        printf("Number is positive\n");
    return 0;
}
