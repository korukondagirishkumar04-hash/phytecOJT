#include<string.h>
#include<stdio.h>
int main()
{
    char str1[100]="problem";
    char str2[30];
    strcpy(str2,str1);
    printf("copy the string:%s",str2);
}