//Program to print size of variables using sizeof() operator.

#include<stdio.h>

int main()
{
    int a;
    char b;
    float c;
    double d;

    printf(" size of int = %lu\n",sizeof(a));
    printf("size of char = %lu\n",sizeof(b));
    printf(" size of float = %lu\n",sizeof(c));
    printf(" size of double = %lu\n",sizeof(d));

    return 0;
}