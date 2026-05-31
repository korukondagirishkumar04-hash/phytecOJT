#include<stdio.h>

int main()
{
    int qua, price = 0, total;
    char size, type;

    printf("===== HOTEL ALPHA =====\n");

    printf("s - Small Pizza  : 150\n");
    printf("m - Medium Pizza : 250\n");
    printf("l - Large Pizza  : 400\n");

    printf("\nSelect Size (s/m/l): ");
    scanf(" %c", &size);

    printf("\n# TYPE #\n");
    printf("v - Veg\n");
    printf("n - Non Veg\n");

    printf("Select Type (v/n): ");
    scanf(" %c", &type);

    printf("Enter Quantity: ");
    scanf("%d", &qua);

    switch(size)
    {
        case 's':
            price = 150;
            break;

        case 'm':
            price = 250;
            break;

        case 'l':
            price = 400;
            break;

        default:
            printf("Invalid Size\n");
            return 0;
    }

    total = price * qua;

    printf("\n===== BILL =====\n");

    if(type == 'v')
    {
        printf("Pizza Type : Veg\n");
    }
    else if(type == 'n')
    {
        printf("Pizza Type : Non Veg\n");
    }
    else
    {
        printf("Invalid Type\n");
        return 0;
    }

    if(size == 's')
    {
        printf("Pizza Size : Small\n");
    }
    else if(size == 'm')
    {
        printf("Pizza Size : Medium\n");
    }
    else
    {
        printf("Pizza Size : Large\n");
    }

    printf("Quantity   : %d\n", qua);
    printf("Total Bill : %d\n", total);

    return 0;
}