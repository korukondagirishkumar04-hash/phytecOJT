#include<stdio.h>
int a,b;



int add(int*a, int*b)
{
    return *a + *b;
}

int sub(int *a, int*b)
{
    return *a - *b;
}

int mul(int *a,int*b)
{
    return *a * *b;
}

int div(int *a,int*b)
{
    return *a / *b;
}



int main()
{
    printf("enter the variables:");
    scanf("%d %d",&a,&b);
    printf("addition %d\n:",add(&a,&b));
    printf("substraction %d\n:",sub(&a,&b));
    printf("multipliaction %d\n:",mul(&a,&b));
    printf("division %d\n:",div(&a,&b));
    
    
    return 0;
}