#include <stdio.h> 
int main() 
{ 
char ch; 
printf("Enter a character: "); 
scanf(" %c", &ch); 
if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
printf(" an Alphabet\n"); 
else 
printf(" NOT an Alphabet\n"); 
return 0; 
}