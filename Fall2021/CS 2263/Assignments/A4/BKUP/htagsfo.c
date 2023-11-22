#include <stdlib.h>
#include <stdio.h>
#include <string.h>
input[100000];

void fileopen(char *x[])
{
    int ch;
    FILE *fptr;
    char *inputptr = &input[0];
    fptr = fopen(*(x + 1), "r");

    while ((ch = fgetc(fptr)) != EOF)
    {
        *inputptr = ch;
        inputptr++;
    }

    fclose(fptr);
}
