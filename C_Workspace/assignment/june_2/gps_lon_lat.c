#include<stdio.h>
int main(){
	char GPS[]="$GPRMC,225446,A,4916.45,N,12311.12,W,000.5,054.7,191194,020.3,E*68";
	for(int i=16; i<25; i++)
		printf("%c",*(GPS+i));
	printf("%c",GPS[23]);
	printf("\n");
	for(int i=26; i<33; i++)
		printf("%c",*(GPS+i));
	printf("%c",GPS[35]);
	printf("\n");
	return 0;
}