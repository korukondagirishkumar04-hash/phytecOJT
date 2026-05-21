#include<stdio.h>
int main()
{
    int num;
  printf("Enter a number: ");
    scanf("%d", &num);
  if(num >= 1 && num <= 100)
        printf("Number is between 1 and 100\n");
    else
        printf("Number is not in range\n");
    return 0;
}
