#include<stdio.h>
#include<string.h>
void bicycle(int,int);
void car(int,int);
void bike(int,int);
void truck(int,int);


void bicycle( int hours, int total)
{
    
    
    printf("how hours do you want to park your vehicle:");
    scanf("%d",&hours);
    
    total =hours*10;
    
    printf("total:%d\n",total);
    printf("thanks for coming");
    
}
void bike( int hours,int total )
{
   
    
    printf("how hours do you want to park your vehicle:");
    scanf("%d",&hours);
    
    total =hours*20;
    
    printf("total:%d\n",total);
    printf("thanks for coming");
    
}
void truck(int hours ,int total )
{
    
    
    printf("how hours do you want to park your vehicle:");
    scanf("%d",&hours);
     
    total =hours*100;
    
    printf("total:%d\n",total);
    printf("thanks for coming");
    
}
void car(int hours, int total )
{
    
    
    
    printf("how hours do you want to park your vehicle:");
    scanf("%d",&hours);
    
    total =hours*50;
    
    printf("total:%d",total);
    printf("thanks for coming");
    
}


int main()
{
    
    char type[40];
    int hours,total;
    
    printf("======GANESH PARKING STATION=====\n");
    printf("====BICYCLE======10,HOURS\n");
    printf("====BIKE======20,HOURS\n");
    printf("====TRUCK======100,HOURS\n");
    printf("====CAR======50,HOURS\n");
    
    
    
    printf("enter type of vehicle:");
    scanf("%s",&type);
    
    if(strcmp(type,"bicycle")==0)
    {
     bicycle(hours,total);   
    }
    else if(strcmp(type,"bike")==0)
    {
        bike(hours,total);
    }
     else if(strcmp(type,"truck")==0)
    {
        truck(hours,total);
    }
     else if(strcmp(type,"car")==0)
    {
        car(hours,total);
    }
    else
    {
        printf("invalid\n");
    }
    
    
}
