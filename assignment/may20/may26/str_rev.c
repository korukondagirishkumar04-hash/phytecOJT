#include<stdio.h>
#include<string.h>
int main()
{
    char str[60],rev[40];
    int i,j=0,len;
    printf("enter the strings:");
    scanf("%s",str);
    len=strlen(str);
    for(i=len-1;i>=0;i--)
    {
        rev[j]=str[i];
        j++;
    }
    printf("orginal name:%s\n",str);
    printf("reversed name:%s\n",rev);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==rev[i])
        {
            printf("%c\n",str[i]);
        }
    }
}