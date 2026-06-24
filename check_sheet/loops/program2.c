//C Program to check entered number is ZERO, POSITIVE or NEGATIVE until user does not want to quit.
#include <stdio.h>
int main()
{
    int num, choice;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if(num > 0)
            printf("Positive\n");
        else if(num < 0)
            printf("Negative\n");
        else
           printf("Zero\n");
        printf("Continue? (1=Yes, 0=No): ");
        scanf("%d", &choice);
    } while(choice == 1);
    return 0;
}