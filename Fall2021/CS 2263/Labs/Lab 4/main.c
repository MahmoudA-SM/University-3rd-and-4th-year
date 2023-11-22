#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *fI = fopen("input.txt", "r");
    if (fI == (FILE*)NULL)
    {
        printf("Error opening input.txt\n");
    }

    FILE *fO = fopen(argv[1], "w");
    if (fO == (FILE*)NULL)
    {
        printf("Error opening %s\n", argv[1]);
    }
    char* s = fgets(stdin, 100, fI);
    fputString(fO, s);
    if(*(s+strlen(s)-1) == '\n')
    {
      s = fgets(stdin, 100, fI);
      fputString(fO, s);
    }
    fclose(fI);
    fclose(fO);
    return EXIT_SUCCESS;
}
