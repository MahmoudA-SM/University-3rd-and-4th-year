#include <stdlib.h>
#include <stdio.h>
int* deepCopy(int* array)
{
    int* arraycp = (int*)malloc(sizeof(int) * 7);
    int i;
    for ( i = 0; i < 7; i++)
    {
        *(arraycp+i) = *(array+i);
        
    }
    return arraycp;
    
}

int main()
{
    int* arrp = (int*)malloc(sizeof(int) * 7);
    int i;
    for (i = 0; i < 7; i++)
    {
        *(arrp+i) = 12+i;
    }
    int *copy = deepCopy(arrp);
    for ( i = 0; i < 7; i++)
    {
        printf("%d ", *(arrp+i));
    }
    printf("\n");
    free(arrp);
    free(copy);
    return EXIT_SUCCESS;
}
