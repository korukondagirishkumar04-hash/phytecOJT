#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    const int *ptr;   

    ptr = &a;         
    printf("Value of a: %d\n", *ptr);

    // *ptr = 15;     

    ptr = &b;         
    printf("Value of b: %d\n", *ptr);

    return 0;
}
