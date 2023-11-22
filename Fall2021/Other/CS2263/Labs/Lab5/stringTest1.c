#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"


int main(int argc, char* argv[])
{
    char* progName;

    progName = duplicateString(argv[0]);

    if(progName == (char*)NULL)
    {
        fprintf(stderr, "Failed");
        return EXIT_FAILURE;
    }

    printf("%s\n", progName);

    freeString(progName);

    return EXIT_SUCCESS;
}