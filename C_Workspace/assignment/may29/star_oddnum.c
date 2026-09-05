#include<stdio.h>
int main(){
    int num;
    int odd=1;
    printf("Enter number :");
    scanf("%d",&num);
    for( int i=1;i<=num;i++){
        for( int j=1;j<=i;j++){
            printf(" %d",odd);
            odd=odd+2;
        }
        printf("\n");
    }
    return 0;
    
}