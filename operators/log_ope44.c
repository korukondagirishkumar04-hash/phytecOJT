#include<stdio.h>
int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
 if(a < 0 || b < 0 || c < 0)
        printf("At least one number is negative\n");
    else
        printf("No negative numbers\n");
  return 0;
}
