//C program to read and print One Dimensional Array of integer elements.


#include<stdio.h>
int main()
{
    int arr[50],n;
    printf("enter the array size:");
    scanf("%d",&n);
    
    printf("enter array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("arrays elements are:");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    
    
}