#include<stdio.h>
int main()
{
    int first,second,third,temp ,j,i,arr[5];
    printf("enter the 5 arrays:\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        
    }
    printf("third largest number:%d",arr[3]);
}