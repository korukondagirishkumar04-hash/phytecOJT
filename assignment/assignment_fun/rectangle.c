#include <stdio.h>
int isre(int  l,int b)
{
  int c=l*b;
  
    return c;
}
int main()
{
    int l,b;
    printf("Enter length");
    scanf("%d",&l);
    printf("Enter breadth");
    scanf("%d",&b);
    int result=isre(l,b);
    printf("Area of a rectangle %d",result);

}

