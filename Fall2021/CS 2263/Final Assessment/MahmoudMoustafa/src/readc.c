#include <stdlib.h>
#include <stdio.h>
int main(){
    FILE* f = fopen("writec.txt", "r");
    char c = fgetc(f);
    fclose(f);
}