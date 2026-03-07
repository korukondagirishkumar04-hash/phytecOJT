#include<stdio.h>
struct emp
{
	char gender:1;
	char mar_stat:5;
	char hobby:3;
	char sceme:4;
};
int main()
{
struct emp e;
printf("%zu",sizeof(e));
}
