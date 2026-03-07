#include<stdio.h>

int main()
{
    unsigned char bcd = 0x47;

    int tens = (bcd >> 4) & 0x0F;
    int unit = bcd & 0x0F;

    int decimal = tens * 10 + unit;

    printf("BCD 0x%02X --> decimal %d\n", bcd, decimal);

    return 0;
}	
