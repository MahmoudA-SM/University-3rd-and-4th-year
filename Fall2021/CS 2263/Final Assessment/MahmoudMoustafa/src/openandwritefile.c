#include <stdlib.h>
#include <stdio.h>
int main(){
    FILE* f = fopen("openwritefile.txt", "w");
    int i = 12345;
    fprintf(f,"%d",i);
    fclose(f);
}