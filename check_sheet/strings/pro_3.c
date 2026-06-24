//C program to count upper case, lower case and special characters in a string.


#include<stdio.h>
int main()
{
    char str[40];
    int i,lower=0,special=0,upper=0;
    
    printf("enter the  string:");
    scanf("%s",str);
    
  
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
        lower++;
        else if(str[i]>='A' && str[i]<='Z')
        upper++;
        else
        special++;
    }
  printf("lower:%d\n",lower);
  printf("upper:%d\n",upper);
  printf("special:%d",special);
    return 0;
}