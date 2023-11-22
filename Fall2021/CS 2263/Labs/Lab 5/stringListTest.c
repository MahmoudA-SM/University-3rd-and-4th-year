#include "Strings.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    String* list = duplicateStringList(argc, argv);
    int i;
    for (i =0; i < argc; i++)
    {
        printf("%s\n", *(list+i));
        // freeString(*(list+i));
    }
    free(list);
    return EXIT_SUCCESS;

}