#include<stdio.h>


int add(int a, int b);

int main()
{
    int a, b, sum;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Function call
    sum = add(a, b);

    printf("Sum = %d", sum);

    return 0;
}

// Function definition
int add(int a, int b)
{
    return a + b;
}
