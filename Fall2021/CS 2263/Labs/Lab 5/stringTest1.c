#include "Strings.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    String copy = duplicateString(argv[0]);
    printf("%s\n", copy);
    freeString(copy);
    return EXIT_SUCCESS;
}