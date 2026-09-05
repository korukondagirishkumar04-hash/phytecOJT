#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100]="hello";
    char str2[40]="girish";
    strcat(str1,str2);
    printf("merging:%s",str1);
}