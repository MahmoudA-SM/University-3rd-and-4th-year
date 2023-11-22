#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*compare)( void *one,  void *two);
typedef char *String;
typedef char **StringList;

String mallocString(int length)
{
    String s = (String)malloc(sizeof(char) * (length + 1));
    if (s == (String)NULL)
    {
        return (String)NULL;
    }
    return s;
}

void freeStringList(int n, StringList s)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(s[i]);
    }
    free(s);
}

void sort(StringList stringlist, int length, compare comp)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (comp(stringlist[j], stringlist[i]) < 0)
            {
                String s = stringlist[i];
                stringlist[i] = stringlist[j];
                stringlist[j] = s;
            }
        }
    }
}

String duplicateString(String string)
{
    int length = strlen(string);

    String copy = mallocString(length);
    if (copy == (String)NULL)
    {
        return (String)NULL;
    }

    strcpy(copy, string);
    return copy;
}

int compareStrings( void *one,  void *two)
{
     String x = (String)one;
     String y = (String)two;

    int shortest = 0;
    int xlength = strlen(x);
    int ylength = strlen(y);

    if (xlength < ylength)
    {
        shortest = xlength;
    }
    else
    {
        shortest = ylength;
    }
    int i;
    for (i = 0; i < shortest; i++)
    {
        if (x[i] != y[i])
        {
            return x[i] - y[i];
        }
    }
    return 0;
}

StringList duplicateStringList(int size, StringList stringList)
{
    StringList stringListCopy;

    stringListCopy = (StringList)malloc(sizeof(String) * size);
    if (stringListCopy == (StringList)NULL)
    {
        fprintf(stderr, "ERROR: duplicateStringList 1. NULL");
        return (StringList)NULL;
    }
    int i;
    int j;
    for (i = 0; i < size; i++)
    {

        stringListCopy[i] = duplicateString(stringList[i]);
        if (stringListCopy[i] == (String)NULL)
        {
            fprintf(stderr, "ERROR: duplicateStringList 2.");

            for (j = 0; j < i; i++)
            {
                free(stringListCopy[j]);
            }
            free(stringListCopy);
            return (StringList)NULL;
        }
    }
    return stringListCopy;
}

int main(int argc, StringList argv)
{
    StringList stringlist = duplicateStringList(argc, argv);
    if (stringlist == (StringList)NULL)
    {
        fprintf(stderr, "ERROR");
        return EXIT_FAILURE;
    }

    sort(stringlist, argc, compareStrings);

    int i;

    for (i = 0; i < argc; i++)
    {
        printf("%s\n", stringlist[i]);
    }

    freeStringList(argc, stringlist);

    return EXIT_SUCCESS;
}