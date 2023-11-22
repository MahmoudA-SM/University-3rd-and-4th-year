#include <stdlib.h>
#include <stdio.h>
int main(){
    int* i = (int*) malloc(sizeof(int));
    *i = 14;
    printf("%d",*i);
    free(i);
    return EXIT_SUCCESS;
}