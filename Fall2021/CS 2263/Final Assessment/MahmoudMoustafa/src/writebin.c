#include <stdlib.h>
#include <stdio.h>
int main(){
    FILE* f = fopen ("writebin.txt","wb");
    int i = 5;
    fwrite(&i, sizeof(i), 1, f);
    fclose(f);
    return EXIT_SUCCESS;
}