#include<stdio.h>

int main()
{
    int choice, quantity;

    do
    {
        printf("\n===== FAST FOOD MENU =====\n");
        printf("1. Idli\n");
        printf("2. Dosa\n");
        printf("3. Vada\n");
        printf("4. Upma\n");
        printf("5. Bonda\n");
        printf("6. Parota\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 6)
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
        }

        switch(choice)
        {
            case 1:
                printf("Idli added to cart!\n");
                break;

            case 2:
                printf("Dosa added to cart!\n");
                break;

            case 3:
                printf("Vada added to cart!\n");
                break;

            case 4:
                printf("Upma added to cart!\n");
                break;

            case 5:
                printf("Bonda added to cart!\n");
                break;

            case 6:
                printf("Parota added to cart!\n");
                break;

            case 7:
                printf("Thank you for visiting!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}
