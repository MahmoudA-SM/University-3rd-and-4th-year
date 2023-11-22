#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE* f = fopen("openfile.txt", "r");
    int i;
    fscanf(f,"%d",&i);
    printf("%d",i);
    fclose(f);
}
