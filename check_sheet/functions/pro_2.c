//2) C program to print Table of an Integer Number using User Define Functions.


#include<stdio.h>
int table(int num)
{
   int i;
   for(i=0;i<12;i++)
   {
       printf("%dx%d=%d\n",num,i,num*i);
   }
    
}


int main()
{
   int num;
   printf("enter the number:");
   scanf("%d",&num);
   table(num);
}