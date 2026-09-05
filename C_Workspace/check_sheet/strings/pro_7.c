//C program to find occurrence of a character in the string.

#include<stdio.h>
#include<string.h>
int main()
{
   char str[60],ch;
   int i,count=0;
   printf("enter the string:");
   scanf("%s",str);
   
   printf("enter the character:");
   scanf(" %c",&ch);
   
   for(i=0;str[i]!='\0';i++)
   {
       if(str[i]==ch)
       {
           count++;
       }
       
   }
   printf("%d",count);
}