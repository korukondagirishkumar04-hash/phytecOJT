//Program to count vowels and consonants in a string using pointer.


#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    char *p;
    int  vowels=0,consonants=0;
    
    printf("enter the string:");
    scanf("%s",&str);
     p=str;
    
    while(*p)
    {
        
        if((*p>='A' && *p<='Z')||(*p>='a' && *p<='z'))
        {
            if(*p=='A'||*p=='E'||*p=='I'||*p=='O'||*p=='U'||*p=='a'||*p=='e'||*p=='i'||*p=='o'||*p=='u')
            {
                vowels++;
            }
            else{
                consonants++;
            }
        }
        p++;
        
    }
    printf("vowels:%d\n",vowels);
    printf("consanants:%d",consonants);
    
    
}