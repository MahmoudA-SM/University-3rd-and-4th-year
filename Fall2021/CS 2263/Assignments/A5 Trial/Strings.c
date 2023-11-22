#include "Strings.h"
#include <stdio.h>
#include <stdlib.h>
String mallocString(int stringsize)
{
    String pc = (String)malloc(sizeof(char) * (stringsize + 1));
    if (pc == (String)NULL)
    {
        return (String)NULL;
    }
    return pc;
}

void freeString(String s)
{
    free(s);
}

String duplicateString(String s)
{
    String copy = mallocString(sizeof(s));
    if (copy == (String)NULL)
    {
        return (String)NULL;
    }
    strcpy(copy, s);
    return copy;
}
StringList duplicateStringList(int i, StringList sl)
{
    StringList copy = (StringList )malloc(sizeof(String) * i);
    int j;
    for (j = 0; j < i; j++)
    {
        copy[j] = sl[j];
    }
    return copy;
}
int compareStrings(void *s1, void *s2)
{
    StringList sc1 = (String*)s1;
    StringList sc2 = (String*)s2;
    return strcmp(*sc1, *sc2);
}

String getString()
{
    String s;
    scanf("%[^\n]", s);
    return s;
}
