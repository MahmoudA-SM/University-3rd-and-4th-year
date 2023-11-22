#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    FILE *fptr;
    char charac;

    
    fptr = fopen(fName, "r"); //put in the file name, I removed the location of the file on my laptop from here

    if(fptr == NULL)
    {
        printf("File could not be opened\n");
        printf("\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        charac = fgetc(fptr);
        putchar(charac);
    }
    while(charac != EOF);

    return EXIT_SUCCESS;
}