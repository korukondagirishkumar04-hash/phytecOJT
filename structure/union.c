#include <stdio.h>
union Data {
    int i;
    float f;
    char c;
};
int main() {
    union Data d;
   d.i = 65;
 printf("As int   : %d\n", d.i);
    printf("As char  : %c\n", d.c);   
 return 0;
}
