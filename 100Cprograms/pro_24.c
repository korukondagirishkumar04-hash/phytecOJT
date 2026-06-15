#include <stdio.h> 
int main() 
{ 
char ch; 
printf("Enter a character: "); 
scanf(" %c", &ch);  
if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' ||
ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
{ 
printf("is a Vowel\n"); 
}
else
{ 
printf("is a Consonant\n"); 
} 
return 0; 
} 