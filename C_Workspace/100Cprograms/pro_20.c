#include <stdio.h> 
int main() 
{ 
 
float sub1, sub2, sub3, sub4, sub5, marks, percentage; 
printf("Enter marks of 5 subjects: "); 
scanf("%f %f %f %f %f", &sub1, &sub2, &sub3, &sub4, &sub5); 
marks = sub1 + sub2 + sub3 + sub4 + sub5; 
percentage = (marks / 500) * 100; 
printf("Total Marks = %.2f\n", marks); 
printf("Percentage = %.2f%%\n", percentage); 
return 0; 
}