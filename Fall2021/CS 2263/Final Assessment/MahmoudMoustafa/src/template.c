#include <stdio.h>
#include <stdlib.h>

void println(char* s);

int main(int argc, char* argv[]){

    println("Hello world");

    return EXIT_SUCCESS;
}

void println(char* s){

    printf("%s\n", s);

    return;
}
