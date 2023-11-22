#include <stdio.h>
#include <stdlib.h>
typedef char* String;
typedef String (*type)();
typedef struct car
{
    String name;
    type t;
}Car;
String SUV(){
    return "SUV\n";
}
String sedan(){
    return "Sedan\n";
}
String coupe(){
    return "Coupe\n";
}
int main(){
    Car* c = (Car*)malloc(sizeof(Car));
    c->name = "Rolls Royce Phantom";
    c->t = &sedan;
    printf("%s\t%s\n",c->name,c->t());
    Car* cc = (Car*)malloc(sizeof(Car));
    cc ->name = "Mercedes Benz G-Class";
    cc->t = &SUV;
    printf("%s\t%s\n",cc->name,cc->t());
    Car* ccc = (Car*)malloc(sizeof(Car));
    ccc->name = "BMW i8";
    ccc->t = &coupe;
    printf("%s\t%s\n",ccc->name,ccc->t());
    return EXIT_SUCCESS;
}