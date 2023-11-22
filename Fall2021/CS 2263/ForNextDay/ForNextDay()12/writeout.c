#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
    FILE* pFIn;
    pFIn = fopen(argv[1], "w");
    char c = getc(stdin);
    if(pFIn == (FILE*)NULL)
    {
        fprintf(stderr, "%s does not exist.\n", argv[1]);
        return EXIT_FAILURE;
    }

    
    while(c != EOF){
        fputc(c, pFIn);
        c = getc(stdin);
    }
    fclose(pFIn);
    return EXIT_SUCCESS;
}