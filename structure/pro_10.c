//Structure Pointer Using User Defined Function

#include<stdio.h>
struct game{
    int jersey;
    int runs;
    char name[54];
};
int display(struct game *p) 
{
 printf("jersey No:%d\n",p->jersey);
 printf("runs:%d\n",p->runs);
 printf("name:%s\n",p->name);
 
}


int main(){
    struct game e={18,25000,"virat"};
     display(&e);
     return 0;
    
}