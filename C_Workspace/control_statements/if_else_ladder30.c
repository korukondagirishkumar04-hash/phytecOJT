/*Write a program to check if a character is a vowel, consonant, digit, or special character using ladder*/

#include<stdio.h>
int main()
{
   char ch;
 printf("Enter a character: ");
    scanf("%c", &ch);
   if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
       ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
    {
        printf("It is a Vowel");
    }
    else if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
    {
        printf("It is a Consonant");
    }
    else if(ch>='0' && ch<='9')
    {
        printf("It is a Digit");
    }
    else
    {
        printf("It is a Special Character");
    }
  return 0;
}
