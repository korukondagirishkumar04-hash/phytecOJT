#include<stdio.h>
int main()
{
    char ch1, ch2;
    printf("Enter two characters: ");
    scanf(" %c %c", &ch1, &ch2);   // space before %c avoids newline issue
   if(ch1 == ch2)
        printf("Characters are equal\n");
    else if(ch1 > ch2)
        printf("%c is greater than %c\n", ch1, ch2);
    else
        printf("%c is less than %c\n", ch1, ch2);
    return 0;
}
