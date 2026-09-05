//C program to read gender (M/F) and print corresponding gender using switch.

#include <stdio.h>
int main()
{
    char gender;
    printf("Enter Gender (M/F): ");
    scanf(" %c", &gender);
    switch(gender)
    {
        case 'M':
        case 'm':
            printf("Male");
            break;

        case 'F':
        case 'f':
            printf("Female");
            break;

        default:
            printf("Invalid Gender");
    }

    return 0;
}