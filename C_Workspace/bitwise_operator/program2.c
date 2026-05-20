#include <stdio.h>
int main()
{
	unsigned char dip_switch=0XA7;
	unsigned char lower_nibble=dip_switch & 0X0F;
		printf("lower 4 bit : %X(decimal %d)\n",lower_nibble,lower_nibble);
	return 0;
	}
