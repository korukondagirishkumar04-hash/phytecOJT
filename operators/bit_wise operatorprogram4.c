#include <stdio.h>
int main()
{
	unsigned char bcd=0X47;
	int tens=(bcd>>4)&0X0f;
	int unit=bcd&0x0f;
	int decimal=tens*10+unit;
	printf("BCD 0x%02X --> decimal %d\n",bcd ,decimal);
		return 0;
}

