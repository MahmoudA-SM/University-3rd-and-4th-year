#include <stdlib.h>
#include <stdio.h>
int main(){
    FILE* f = fopen("writec.txt", "w");
    char c = 'c';
    fputc(c, f);
    fclose(f);
}