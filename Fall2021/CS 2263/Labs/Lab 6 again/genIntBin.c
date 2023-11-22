#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
int main(int argc, char **argv)
{
    FILE *fout = fopen(argv[2], "wb");
    srand(time(0));
    int i;
    int size = atoi(argv[1]);
    int array[size];
    fwrite(&size, sizeof(size), 1, fout);
    for ( i = 0; i < size; i++)
    {
        int x = rand()/10000;  
        array[i] = x;      
    }
    fwrite(array, sizeof(array), 1, fout);
    return EXIT_SUCCESS;
}