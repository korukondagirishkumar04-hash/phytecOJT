//C program to print string one by one characters using loop.


#include<stdio.h>
int main()
{
    char str[40];
    int i;
    printf("enter the charcter:");
    scanf("%s",str);

    for(i=0;str[i]!='\0';i++)
    {
        printf("%c",str[i]);
    }
}