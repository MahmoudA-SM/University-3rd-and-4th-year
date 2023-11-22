#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
int main(int argc, char** argv){
    FILE* fIN = fopen(argv[1], "rb");
    int size;
    fread(&size, sizeof(size), 1, fIN);
    int num;
    int i;
    for(i = 0; i < 10000; i++){
        fread(&num, sizeof(num), 1, fIN);
        printf("%d ", num);
    }

    return EXIT_SUCCESS;
}