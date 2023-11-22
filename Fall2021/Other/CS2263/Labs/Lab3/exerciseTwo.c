#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {10, 11, 12, 13, 14, 15, 16};

    int i;
    int *ptr = arr;

    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d", i);
        printf("\t\t");
        printf("%d", arr[i]);
        printf("\t\t");
        printf("%d%p", arr[i]);
        printf("\t\t");
        printf("%d", *ptr++);
        printf("\n");
        printf("\n");
    }
}