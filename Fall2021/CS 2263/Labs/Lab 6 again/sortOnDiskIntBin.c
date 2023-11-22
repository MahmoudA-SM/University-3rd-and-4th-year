#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
void Sort(FILE *fIN, int* size)
{

    int n;    // to be read
    int num;  // to be read
    int i, j; // loop variables

    for (i = 0; i < *size; i++)
    {

        for (j = i+1; j < *size; j++)
        {

            fread(&n, sizeof(int), 1, fIN);
            fread(&num, sizeof(int), 1, fIN);
            fseek(fIN, -(2 * sizeof(int)), SEEK_CUR);

            if (n > num)
            {
                // fseek(fIN, (-2 * sizeof(int)), SEEK_CUR);
                fwrite(&num, sizeof(num), 1, fIN);
                fwrite(&n, sizeof(n), 1, fIN);
                fseek(fIN, (-1 * sizeof(int)), SEEK_CUR);
            }

            else
            {
                // fseek(fIN, (-2 * sizeof(int)), SEEK_CUR);
                fwrite(&n, sizeof(n), 1, fIN);
                fwrite(&num, sizeof(num), 1, fIN);
                fseek(fIN, (-1 * sizeof(int)), SEEK_CUR);
            }
        }
        fseek(fIN, 1, SEEK_SET);
    }
}

int main(int argc, char **argv)
{

    struct timeval startTime;
    struct timeval endTime;
    float elapsedTime;
    FILE *fIN = fopen(argv[1], "rb+");
    int size;
    fread(&size, sizeof(size), 1, fIN);
    // printf("%d\n", size);
    gettimeofday(&startTime, NULL);
    Sort(fIN, &size);
    gettimeofday(&endTime, NULL);

    elapsedTime = (endTime.tv_sec - startTime.tv_sec) + 1e-6 * (endTime.tv_usec - startTime.tv_usec);
    fprintf(stderr, "Time for processing %d records= %f\n", size, elapsedTime);

    fclose(fIN);
    return EXIT_SUCCESS;
}
