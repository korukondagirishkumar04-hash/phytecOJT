#include<stdio.h>
int main()
{
    float length,breadth,area;
    printf("enter the length and breadth:");
    scanf("%f %f",&length,&breadth);
    
    area =length*breadth;
    printf("area of rectangle:%f\n",area);
    return 0;
    
}