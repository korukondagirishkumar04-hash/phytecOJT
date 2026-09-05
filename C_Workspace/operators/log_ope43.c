#include<stdio.h>
int main()
{
    int a, b, c;
  printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    if(a > 0 && b > 0 && c > 0)
        printf("All numbers are positive\n");
    else
        printf("Not all numbers are positive\n");
    return 0;
}
