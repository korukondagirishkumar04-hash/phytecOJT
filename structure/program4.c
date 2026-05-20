#include<stdio.h>
struct Point{
	int x;
	int y;
};
void printPoint(struct Point p){
	printf("(%d%d)\n",p.x,p.y);
}
int main(){
	struct Point p1={5,12};
	struct Point p2={-3,7};
	printPoint(p1);
	printPoint(p2);
	return 0;
}
