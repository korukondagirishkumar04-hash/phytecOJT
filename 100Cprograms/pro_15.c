#include <stdio.h> 
int main() 
{ 
 
int n; 
printf("Enter a number: "); 
scanf("%d", &n); 
if (n > 0)
printf("is Positive\n"); 
else if (n < 0)
printf("is Negative\n"); 
else 
printf("The number is Zero\n"); 
return 0;
}