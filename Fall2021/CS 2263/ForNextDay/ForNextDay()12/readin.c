#include <stdio.h>
#include <stdlib.h>
int main(int argc, int* argv[])
{
    FILE *pFIn = fopen(argv[1], "r");
    char c = fgetc(pFIn);
    if (pFIn == (FILE*)NULL)
    {
        fprintf(stderr, "%s does not exist.\n", argv[1]);
        return EXIT_FAILURE;
    }
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(pFIn);
    }
    fclose(pFIn);
    return EXIT_SUCCESS;
}
