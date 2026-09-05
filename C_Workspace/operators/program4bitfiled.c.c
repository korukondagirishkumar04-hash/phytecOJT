#include<stdio.h>
struct PacketHeader{
	unsigned int version :4;
	unsigned int type :3;
	unsigned int reserved :1;
	unsigned int length :16;
	unsigned int sequence :8;
};
int main()
{
	struct PacketHeader header={
		.version =2,
		.type =5,
		.length =512,
		.sequence =45
	};
	printf("Header size:%zubytes\n",sizeof(header));
	printf("Raw value:0x%08X\n",*(unsigned int*)&header);
	return 0;
}
