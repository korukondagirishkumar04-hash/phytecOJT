#include<stdio.h>
int main()
{
	int length,width;
	printf("enter the values");
	scanf("%d,%d",&length,&width);
	printf("arearectangle:%d\n",length*width);
	printf("perimeter:%d\n",2*(length+width));
	return 0;
}
