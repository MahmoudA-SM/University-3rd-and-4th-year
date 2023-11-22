#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
void Sort(int *array, int size)
{
    int temp; // for swapping positions (if needed)
    int i, j; // loop variables
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main(int argc, char **argv)
{
    FILE *fIn = fopen(argv[1], "rb");
    int size;
    fread(&size, sizeof(size), 1, fIn);
    struct timeval startTime;
    struct timeval endTime;
    float elapsedTime;
    int *array = (int *)malloc(sizeof(int) * size);
    int num;
    int i;

    for (i = 0; i < size; i++)
    {
        fread(&num, sizeof(num), 1, fIn);
        array[i] = num;
        // printf("%d", num);
    }

    // calculate elapsed time
    gettimeofday(&startTime, NULL);
    Sort(array, size);
    gettimeofday(&endTime, NULL);

    elapsedTime = (endTime.tv_sec - startTime.tv_sec) + 1e-6 * (endTime.tv_usec - startTime.tv_usec);
    fprintf(stderr, "Time for processing %d records= %f\n", size, elapsedTime);

    FILE *fOut = fopen(argv[2], "wb");
    int n;
    fwrite(&size, sizeof(size), 1, fOut);

    for (i = 0; i < size; i++)
    {
        n = array[i];
        fwrite(&n, sizeof(n), 1, fOut);
    }

    return EXIT_SUCCESS;
}
