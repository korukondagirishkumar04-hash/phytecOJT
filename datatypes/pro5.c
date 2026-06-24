//Program to find largest number among three numbers.


#include<stdio.h>

int main()
{
    int a,b,c;

    printf("Enter three numbers: ");
    scanf("%d%d%d",&a,&b,&c);

    if(a>b && a>c){
        printf(" a is Largest = %d",a);
    }
    else if(b>c){
        printf("b is Largest = %d",b);
    }
    else{
        printf(" c is Largest = %d",c);
}
    return 0;
}