#include <stdlib.h>
#include <stdio.h>
int main(){
    FILE* f = fopen("writes.txt", "w");
    char* s = "A7a";
    fputs(s,f);
    fclose(f);
}