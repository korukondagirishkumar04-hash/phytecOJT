//Program to read array elements and print with addresses.

#include<stdio.h>
int main()
{
    int arr[5];
    printf("enter the arrays:");
    for(int i=0;i<5;i++)
        {
    scanf("%d",&arr[i]);
        }
    printf("address elements:");
        for(int i=0;i<5;i++){
            printf("value:%d\n",arr[i]);
            printf("address:%p",&arr[i]);
        }
       
}