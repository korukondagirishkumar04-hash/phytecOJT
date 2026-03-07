#include<stdio.h>
int main()
{
        int num, pos;
        printf("Enter number: ");
        scanf("%d", &num);
	printf("Enter bit position to set (0-based): ");
        scanf("%d", &pos);
        num = num | (1 << pos);   
   printf("After setting bit: %d\n", num);
      return 0;
}
