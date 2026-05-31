#include<stdio.h>
int main()
{
    int num;
   printf("Enter a number: ");
    scanf("%d", &num);
    (num > 0) ? printf("Positive\n") :
    (num < 0) ? printf("Negative\n") :
                printf("Zero\n");
                return 0;
}
