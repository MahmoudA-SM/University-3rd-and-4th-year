#include <stdlib.h>
#include <stdio.h>
int main(){
    FILE* f = fopen ("writebin.txt","rb");
    int i;
    fread(&i,sizeof(i), 1, f);
    fclose(f);
    return EXIT_SUCCESS;
}