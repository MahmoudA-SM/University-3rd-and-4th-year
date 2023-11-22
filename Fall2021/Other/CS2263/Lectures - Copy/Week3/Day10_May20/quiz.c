#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(const char *p)
{
    char *q;
    strcpy(q, p);
    return q;
}

int main()
{
    char* a;
    duplicate(a);
}