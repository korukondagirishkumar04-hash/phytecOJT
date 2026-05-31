#include<stdio.h>
int main()
{
    char str[40];
    printf("enter the string:");
    scanf("%s",str);
    printf("CHARACTER\n");
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            printf("%c\n",str[i]);
        }
    }
    printf("numbers\n");
    for(int i=0;str[i]!=0;i++)
    {
        if(str[i]>='1' && str[i]<='9')
        {
            printf("%c\n",str[i]);
        }
    }
    
    return 0;
    
}