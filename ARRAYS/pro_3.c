//C program to find Smallest and Largest elements from One Dimensional Array Elements.


#include<stdio.h>
int main()
{
    int arr[100],n;
    int  max,min;
    printf("array size:");
    scanf("%d",&n);
    
    printf("array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    max=min=arr[0];
    for(int i=0;i<n;i++)
    {
       if(arr[i]>max)
       max=arr[i];
       
       if(arr[i]<min)
       min=arr[i];
    }
    printf("max:%d\n",max);
    printf("min:%d",min);
    
}