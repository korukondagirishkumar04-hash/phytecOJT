#include <stdio.h>
float add(float,float);
float add(float a, float b)
{
    return a + b;
}
float subtract(float,float);
float subtract(float a, float b)
{
    return a - b;
}
float multiply(float,float);
float multiply(float a, float b)
{
    return a * b;
}
float divide(float,float);
float divide(float a, float b)
{
    return a / b;
}
int  modulus(int,int);
int modulus(int a, int b)
{
    return a % b;
}
float square(float);
float square(float a)
{
    return a * a;
}
float cube(float);
float cube(float a)
{
    return a * a * a;
}

int main()
{
    int choice;
    float num1, num2;

    printf("===== CALCULATOR =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Square\n");
    printf("7. Cube\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result = %.2f", add(num1, num2));
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result = %.2f", subtract(num1, num2));
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result = %.2f", multiply(num1, num2));
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);

            if(num2 != 0)
                printf("Result = %.2f", divide(num1, num2));
            else
                printf("Division by zero not possible");

            break;

        case 5:
            printf("Enter two integers: ");
            scanf("%f %f", &num1, &num2);
            printf("Result = %d", modulus((int)num1, (int)num2));
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%f", &num1);
            printf("Result = %.2f", square(num1));
            break;

        case 7:
            printf("Enter a number: ");
            scanf("%f", &num1);
            printf("Result = %.2f", cube(num1));
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
