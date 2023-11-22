#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void fileopen(char *x[])
{
    char* input = (char*) malloc(sizeof(char)*100000);
    int ch;
    FILE *fptr;
    char *inputptr = input;
    fptr = fopen(*(x + 1), "r");

    while ((ch = fgetc(fptr)) != EOF)
    {
        *inputptr = ch;
        inputptr++;
    }

    fclose(fptr);
}
