#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* mallocString(int stringsize)
{
    char *sAlloc = malloc(sizeof(char)*(stringsize+1));

    if(sAlloc == (char*)NULL)
    {
        printf("Memory could not be allocated\n");
        return sAlloc;
    }

    return sAlloc;
}


void freeString(char* s)
{
    free(s);
}


char* duplicateString(char* s)
{
    char* dup;

    int var = sizeof(strlen(s)+1);
    dup = mallocString(var);

    if(dup == (char*)NULL)
    {
        return (char*)NULL;
    }
    strcpy(dup, s);
    return dup;
}