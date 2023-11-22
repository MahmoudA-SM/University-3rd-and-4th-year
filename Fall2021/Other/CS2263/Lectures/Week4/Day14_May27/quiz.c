#include <stdio.h>
#include <stdlib.h>

int *doubleSize(int *a, int n)
{
    int *b = malloc(2*n*sizeof(int));

    if(b == NULL)
    {
        return NULL;
    }

    int i;
    for(i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    return b;
}