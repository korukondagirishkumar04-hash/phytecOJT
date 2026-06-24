//Program to Demonstrate Structure Pointer

#include<stdio.h>
struct friends{
    int count;
    char names[54];
};
int main()
{
    struct friends s={1 ,"girish"};
    struct friends *p;
    p=&s;
    
    printf("count:%d\n",s.count);
    printf("names:%s\n",s.names);
    return 0;
    
}