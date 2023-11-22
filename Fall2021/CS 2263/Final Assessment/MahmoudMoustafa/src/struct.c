#include <stdio.h>
#include <stdlib.h>
typedef char* String;
typedef struct car
{
    String name;
    int model
}Car;
int main(){
    Car* c;
    c = (Car*)malloc(sizeof(Car));
    c->name = "Lexus";
    c->model = 2022;
    free(c);
    return EXIT_SUCCESS;
}