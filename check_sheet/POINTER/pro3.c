// Program to print a string using pointer.


#include<stdio.h>
int main()
{
    char str[]="Girish kumar";
    char *ptr=str;
    
    while(*ptr)
    
    {
        printf("%c",*ptr);
       ptr++;
    }
    return 0;
    
}