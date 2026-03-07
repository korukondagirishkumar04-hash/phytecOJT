/* Write a program to check if a character is uppercase or lowercase using if-else*/

#include<stdio.h>
int main()
{
	char ch;
	printf("enter the character");
	scanf("%c",&ch);
	if(ch>='A'  && ch<='Z'){
	       printf("upper case");
	}
      else{ 
      printf("lower case");
      }
return 0;
}
