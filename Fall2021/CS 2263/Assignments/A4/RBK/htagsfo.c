#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void fileopen(char *x[])
{
    char* input = (char*) malloc(sizeof(char)*100000);
    char input[100000];
    int ch;
    FILE *fptr;
    char *inputptr;
    inputptr = input;
    fptr = fopen(*(x + 1), "r");

    while ((ch = fgetc(fptr)) != EOF)
    {
      printf("ch = %c\n", ch);

      printf("*inputptr = %c\n", *inputptr);
      // *input = ch;
      // input++;

        *inputptr = ch;
        inputptr++;
    }

    fclose(fptr);
}
