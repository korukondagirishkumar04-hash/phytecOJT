#include<stdio.h>

void swap(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;

    printf("after  swapping: %d %d\n", a, b);
}

int main()
{
    int x, y;

    printf("Enter numbers: ");
    scanf("%d %d", &x, &y);

    swap(x, y);

    printf("before main: %d %d\n", x, y);

    return 0;
}