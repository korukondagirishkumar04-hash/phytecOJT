//C program to print square, cube and square root of all numbers from 1 to N.
#include<stdio.h>
#include<math.h>
int main()
{
    int n, i;

    printf("Enter N: ");
    scanf("%d", &n);

    printf("Number\tSquare\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d\t%d\n",
               i,
               i * i);
    }
    
     printf("Number\tcube\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d\t%d\n",
               i,
               i * i * i);
    }
    
    printf("Number\tsquareroot\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d\t%f\n",
               i,
               sqrt(i));
    }

    return 0;
}