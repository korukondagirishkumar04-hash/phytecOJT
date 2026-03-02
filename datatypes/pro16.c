#include<stdio.h>
int main()
{
	int length,breadth,area,perimeter;
	printf("enter length");
	scanf("%d\n",&length);
	printf("enter breadth");
	scanf("%d\n",&breadth);
	area=length*breadth;
	perimeter=2*(length+breadth);
	printf(" areaof rectangle:%d\n",area);
	printf(" perimeterof rectangle:%d\n",perimeter);
	return 0;
}
