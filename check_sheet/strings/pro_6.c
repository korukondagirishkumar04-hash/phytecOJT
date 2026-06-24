//C program to reverse string in same variable, without using another string variable to reverse.

#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    int i,temp,len;
    printf("enter the string:");
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len/2;i++)
    {
       char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
    printf("reversed:%s",str);
}