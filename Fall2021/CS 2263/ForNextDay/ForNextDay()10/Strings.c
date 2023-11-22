#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"
#include <string.h>

char* mallocString (int stringsize)
{
    char* pc = (char*) malloc( sizeof(char)*(stringsize+1));
    if(pc ==(char*)NULL)
    {
        return (char*)NULL;
    }
    return pc;
}

void freeString(char* s)
{
    free(s);
}

char* duplicateString (char* s)
{
    char* copy = mallocString(sizeof(s));
    if (copy == (char*)NULL)
    {
        return (char*) NULL;
    }
    strcpy(copy, s);
    return copy;
}