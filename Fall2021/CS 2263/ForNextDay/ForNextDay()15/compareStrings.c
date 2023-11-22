#include <stdlib.h>
#include <stdio.h>
#include "Strings.c"
int compareString(char *str1, char *str2) 
{ 
    char **str1P = (char**) str1;
    char **str2P = (char**) str2;
    return strcmp(*str1P, *str2P); 
} 
int main(int argc, char* argv[])
{
    char* stringsArray[] = {"Hello","World", "Name", "Age"};
    printf("Array contents:\n");
    int i;
    for(i = 0; i < 4; i++)
    {
        printf("%s ", stringsArray[i]);
    }
    printf("\n");

    printf("Array after ordering:\n");
    qsort(stringsArray, 4, sizeof(char*), compareString);
    for ( i = 0; i < 4; i++)
    {
        printf("%s\n", stringsArray[i]);
    }    
}
