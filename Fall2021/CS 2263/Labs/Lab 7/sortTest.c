#include <stdio.h>
#include <stdlib.h>

void sort(int *array, int length)
{
    int i, j, temp;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (array[j] < array[i])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printArray(int array[], int var)
{
    int i;
    for(i = 0; i < var; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {69,6,9,96,4,1,52,100};
    int arrayLength = sizeof(array)/sizeof(array[0]);
    
    printf("Array before sorting: \n");

    printArray(array, arrayLength);

    sort(array, arrayLength);

    printf("Array after sorting: \n");

    printArray(array, arrayLength);

    return EXIT_SUCCESS;
}