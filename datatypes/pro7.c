#include <stdio.h>
int main()
{
int a = 3, b = 9, temp;
temp = a;
 a = b;
  b = temp;
printf("After swap: a = %d, b = %d\n", a, b);
return 0;
}
