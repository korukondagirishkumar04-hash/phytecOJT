#include<stdio.h>
struct Rectangle{
	int length;
	int breadth;
};
void calculateAreaPerimeter(struct Rectangle *r){
	int area=r->length*r->breadth;
	int peri=2*(r->length+r->breadth);
	printf("Area =%d\n",area);
	printf("Perimeter =%d\n",peri);
}
int main(){
	struct Rectangle rect={10,6};
	printf("Rectangle%d%d\n",rect.length,rect.breadth);
	calculateAreaPerimeter(&rect);
	return 0;
}
