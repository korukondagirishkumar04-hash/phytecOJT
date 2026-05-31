#include <stdio.h>
#define alarm 0X01
#define fault 0X04
#define warning 0x10
int main()
{
	unsigned char flags=0x15;
	if(flags &(alarm | fault))
	{
		printf("alarm or fault is active ");
	}
	return 0;
}
