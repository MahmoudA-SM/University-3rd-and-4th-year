#include <stdio.h>
#include <stdlib.h>

int minMax(int a[], int n, int *mx, int *mn)
{
    int i;
    int max;
    int min;

    for(i = 0; i < n; i++)
    {
        printf("Enter values to be put into the array: ");
        int var;
        var = scanf("%d", &a[i]);
    }

    max = a[0];
    min = a[0];

    for(i = 0; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
        else
        {
            if(a[i] < min)
            {
                min = a[i];
            }
        }
    }

    printf("The highest value is: %d\n", max);
    printf("The smallest value is: %d\n", min);
}