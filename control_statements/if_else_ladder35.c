/*  Write a program to display BMI category (Underweight, Normal, Overweight, Obese)using ladder*/

#include<stdio.h>
int main()
{
    float bmi;
      printf("Enter BMI: ");
    scanf("%f", &bmi);
    if(bmi < 18.5)
    {
        printf("Category: Underweight");
    }
    else if(bmi < 25)
    {
        printf("Category: Normal");
    }
    else if(bmi < 30)
    {
        printf("Category: Overweight");
    }
    else
    {
        printf("Category: Obese");
    }
    return 0;
}
