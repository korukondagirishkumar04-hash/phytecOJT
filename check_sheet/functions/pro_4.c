//4) C program to find Length of the String by passing String/ Character Array as an Argument using User Define Functions.


#include<stdio.h>
int lengthstr(char str[])
{
   int i=0;
   while(str[i]!='\0')
   {
       i++;
   }
   return i;
    
}


int main()
{
    char str[23];
    printf("enter the string:");
    scanf("%s",str);
    printf("%d",lengthstr(str));
}