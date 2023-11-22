#include <stdio.h>
#include <stdlib.h>

int main(int argc, int * * argv)
{
    int x = -2;
    int arr[] = {0, 1, 2, 3, 4};
    int y = 15;

    printf("& x      = %p, & y      = %p\n", &x, &y);
    printf("& arr[0] = %p, arr[4] = %p\n", &arr[0], &arr[4]);
    printf("x = %d, y = %d\n", x, y);
    printf("Memory address of x: %p", &x);
    printf("\n");
    printf("Memory address of y: %p", &y);
    printf("\n");

    arr[-1] = 7;
    arr[5] = -23;

    printf("\n");
    printf("x = %d, y = %d\n", x, y);
    printf("Memory address of x: %p", &x);
    printf("\n");
    printf("Memory address of y: %p", &y);
    printf("\n");

    arr[6] = 108;

    printf("\n");
    printf("x = %d, y = %d\n", x, y);
    printf("Memory address of x: %p", &x);
    printf("\n");
    printf("Memory address of y: %p", &y);
    printf("\n");
  

    arr[7] = -353;

    printf("\n");
    printf("x = %d, y = %d\n", x, y);
    printf("Memory address of x: %p", &x);
    printf("\n");
    printf("Memory address of y: %p", &y);
    printf("\n");
    printf("\n");

    int i;
    for(i = 0; i < 5; i++)
    {
        printf("The memory address is: %d%p", arr[i]);
        printf("\n");
    }

    return EXIT_SUCCESS;
}