#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copyString(char* str)
{
    int length = sizeof(strlen(str)+1);

    char* copy = malloc(length);

    int i;
    for(i = 0; i < length; i++)
    {
        *copy = *str;
    }

    return copy;
}

int main()
{
    char arr[5] = "";
    char *ptr = arr;

    char *var = copyString(ptr);

    int i;
    for(i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        printf("%c\t%p", arr[i], &arr[i]);
        printf("\n");
    }

    printf("\n");
    printf("\n");

    int j;
    for(j = 0; j < (sizeof(arr)/sizeof(arr[0])); j++)
    {
        printf("%c\t%p", var[i], &var[i]);
        printf("\n");
    }
}