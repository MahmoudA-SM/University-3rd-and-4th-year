#include "Strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main(int argc, char* argv[])
{
    String* list = duplicateStringList(argc, argv);
    int i;
    qsort(list,argc,sizeof(String),compareStrings);
    for (i =0; i < argc; i++)
    {
        printf("%s\n", *(list+i));
        // freeString(*(list+i));
    }
    free(list);
    return EXIT_SUCCESS;

}