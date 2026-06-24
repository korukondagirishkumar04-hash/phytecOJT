//5) C program to find Total Amount of purchased Items by Passing Structure as an Argument using User Define Functions.


#include<stdio.h>
struct item{
    char name[34];
    int quality;
    float price;
};
int cost(struct item item)
{
    return item.price*item.quality;
    
}
int main()
{
    struct item item;
    printf("enter the name\n");
    scanf("%s",item.name);
    printf("enter the quality\n");
    scanf("%d",&item.quality);
    printf("enter the price\n");
    scanf("%f",&item.price);
    
    printf("item name:%s\n",item.name);
    printf("price:%d",cost(item));
    
}