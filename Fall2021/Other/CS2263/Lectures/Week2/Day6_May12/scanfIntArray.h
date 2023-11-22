#include <stdio.h>
#include <stdlib.h>

int main(int a[], int n)
{
    int i;
    //int num;
    int count = 0;

    for(i = 0; i < n; i++)
    {
        printf("Enter values to be put into the array: ");
        int var;
        var = scanf("%d", &a[i]);

        if(var != 1)
        {
            printf("Error. Input could not be taken. \n");
            return EXIT_FAILURE;
        }

        else
        {
            count++;
        }
    }

    return count;
}