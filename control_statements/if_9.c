#include<stdio.h>
int main()
{
    int day;
    printf("Enter day number: ");
    scanf("%d",&day);
    if(day == 6 || day == 7)
    {
        printf("Weekend");
    }
    return 0;
}
