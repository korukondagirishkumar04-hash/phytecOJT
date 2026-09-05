//C program to check whether a character is VOWEL or CONSONANT using switch.

#include<stdio.h>
int main()
{
    char ch;
    
    printf("enter the character:");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        printf("vowels");
        break;
        
        default:
        printf("consonant");
        
    }
}