//Program to print size of different types of pointer variables.


#include<stdio.h>
int main()
{
    int *a;
    float *b;
    char *ch;
    double *d;
    
    
printf("size of int : %zu\n", sizeof(a));
printf("size of float  : %zu\n", sizeof(b));
printf("size of char  : %zu\n", sizeof(ch));
printf("size of double  : %zu\n", sizeof(d));
       return 0;
    
    
}