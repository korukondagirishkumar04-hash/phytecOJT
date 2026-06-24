#include<stdio.h>
int main()
{
    int a=10;
    int *p;
    p=&a;
    printf("value:%d\n",a);
    printf("address:%d\n",&a);
    printf("value:%d\n",p);
    printf("address:%d",*p);
    return 0;
}