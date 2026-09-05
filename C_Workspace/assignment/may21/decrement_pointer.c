#include<stdio.h>
int main()
{
    int a,b;
    printf("enter the number:");
    scanf("%d",&a);
    int *x=&a;
    (*x)++;
    printf("after increment:%d\n",*x);

//decrement
printf("enter the number:");
scanf("%d",&b);
int (*y)=&b;
(*y)--;
printf("after decreemnt:%d\n",(*y));
}