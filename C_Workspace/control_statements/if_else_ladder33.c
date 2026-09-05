/*Write a program to categorize age group: Child, Teenager, Adult, Senior using ladder*/

#include<stdio.h>
int main()
{
    int age;
    printf("Enter the age: ");
    scanf("%d", &age);
   if(age >= 0 && age <= 12)
    {
        printf("Age Group: Child");
    }
    else if(age <= 19)
    {
        printf("Age Group: Teenager");
    }
    else if(age <= 59)
    {
        printf("Age Group: Adult");
    }
    else
    {
        printf("Age Group: Senior");
    }
   return 0;
}
