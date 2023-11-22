#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int copying(const int *var1, int var2)
{
    int *ptr = malloc(var2 * sizeof(*ptr));

    int *var3 = ptr;

    int i;
    for(i = 0; i < var2; i++, var1++, ptr++)
    {
        *ptr = *var1;
    }
    return var3;
}


int main()
{
    int arr[5] = {5, 10, 15, 20, 25};
    int *arrPtr = arr;

    int *num = copying(arrPtr, 5);

    int i;
    for(i = 0; i < 5; i++)
    {
        printf("%d\t%p", arr[i], &arr[i]);
        printf("\n");
    }

    printf("\n");
    printf("\n");

    int j;
    for(j = 0; j < 5; j++)
    {
        printf("%d\t%p", num[i], &num[i]);
        printf("\n");
    }

    return EXIT_SUCCESS;
}