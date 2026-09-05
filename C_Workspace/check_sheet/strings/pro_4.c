//C program to convert string in upper case and lower case.


#include<stdio.h>
int main()
{
    char str[50];
    int i;
    
    printf("enter the string:");
    scanf("%s",str);
    
    printf("\nuppercase:");
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            printf("%c",str[i]-32);
        }
        else
        {
        printf("%c",str[i]);
        }
    }
    
    printf("\nlower case:");
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            printf("%c",str[i]+32);
        }
        else
        {
        printf("%c",str[i]);
        }
    }
    
}