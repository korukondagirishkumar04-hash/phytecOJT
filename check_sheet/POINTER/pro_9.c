// Program to demonstrate example of array of pointers.


#include<stdio.h>
int main()
{
int a=10,b=70,c=59;
int *p[3];
p[0]=&a;
p[1]=&b;
p[2]=&c;
for(int i=0;i<3;i++)
{
    printf("array:%d\n",*p[i]);
}

}