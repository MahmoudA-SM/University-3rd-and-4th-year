#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compareString(const void* var1, const void* var2)
{
    const char **ch1 = (const char **)var1;
    const char **ch2 = (const char **)var2;

    return strcmp(*ch1, *ch2);
}