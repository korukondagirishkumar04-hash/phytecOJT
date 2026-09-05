// Program to Add Two Distances in Feet and Inches Using Structure

#include<stdio.h>
struct distance{
    int feet;
    int inches;

};
int main()
{
    struct distance d1,d2,sum;
    printf("enter first distance(feet,distance):");
    scanf("%d %d",&d1.feet,&d1.inches);
    
    printf("enter second distance(feet inches) ");
    scanf("%d%d",&d2.feet,&d2.inches);
    
    sum.feet=d1.feet+d2.feet;
    sum.inches=d1.inches+d2.inches;
    /*if(sum.inches>=12)
    {
        sum.feet++;
        sum.inches-=12;
    }*/
    printf("total distance:%d",sum.feet,sum.inches);
    
}