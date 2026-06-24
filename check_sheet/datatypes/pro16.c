// Program to demonstrate example of global and local scope.

#include <stdio.h>

int x = 100;   

void display()
{
    int y = 50;   

    printf("Global = %d\n", x);
    printf("Local = %d\n", y);
}
int main()
{
    display();
    return 0;
}