#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    FILE *fptr;

    char *ch = "Programming Language";

    fptr = fopen(argv[1], "w");

    if(fptr == (FILE*)NULL)
    {
        fprintf(stderr, "Could not open file (%s)\n", argv[1]);
        printf("\n");

        return EXIT_FAILURE;
    }

    fputs(ch, fptr);
    fclose(fptr);

    return EXIT_FAILURE;
}