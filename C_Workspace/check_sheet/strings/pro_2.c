//C program to print all VOWEL and CONSONANT characters separately.

#include<stdio.h>
int main()
{
    char str[40];
    int i;
    
    printf("enter the  string:");
    scanf("%s",str);
    
  
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='o'||str[i]=='u'||str[i]=='i'||str[i]=='A'||str[i]=='E'||str[i]=='O'||str[i]=='U'||str[i]=='I')
        {
        printf(" \nvowels:%c",str[i]);
        }
    }
    
    for(i=0;str[i]!='\0';i++)
    { 
        if(!(str[i]=='a'||str[i]=='e'||str[i]=='o'||str[i]=='u'||str[i]=='i'||str[i]=='A'||str[i]=='E'||str[i]=='O'||str[i]=='U'||str[i]=='I'))
        {
            
        
        
        printf("\nconsonants:%c",str[i]);
        }
    }
    
}