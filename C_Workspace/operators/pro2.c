#include<stdio.h>
#define alarm 0*01
#define fault 0*04
#define warning 0*10
int main()
{
	unsigned char flags=0*15;
	if(flags & (alarm | fault))
	{
		printf("alarm or fault is active");
	}
	return 0;
}
