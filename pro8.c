#include <stdio.h>
int main()
{
int p= 4, q = 6;
p = p + q;
q = p - q;
p= p - q;
printf("After swap: p = %d, q = %d\n", p, q);
return 0;
}
 
