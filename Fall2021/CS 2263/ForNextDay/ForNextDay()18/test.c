#include "Strings.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc, StringList argv)
{
    StringList copy = duplicateStringList(argc, argv);
    int i;
    for(i = 0; i < argc; i++){
        printf("%s\n", copy[i]);
    }
    return EXIT_SUCCESS;
}
