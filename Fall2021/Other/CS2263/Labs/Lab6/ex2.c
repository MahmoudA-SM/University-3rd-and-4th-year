#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


void sortNum(int arr[], int a, int b)
{
    int num1;
    int num2;
    int num3;
    int num4;

    if(a < b)
    {
        num1 = a;
        num2 = a;
        num3 = b;

        while(num2 < num3)
        {
            while(arr[num2] <= arr[num1] && num2 <= b)
            {
                num2++;
            }

            while(arr[num3] > arr[num1] && num3 >= 1)
            {
                num3--;
            }

            if(num2 < num3)
            {
                num4 = arr[num2];
                arr[num2] = arr[num3];
                arr[num3] = num4;
            }
        }

        num4 = arr[num3];
        arr[num3] = arr[num1];
        arr[num1] = num4;

        sortNum(arr, 1, num3-1);
        
        sortNum(arr, num3+1, b);
    }
}


int main(int argc, char** argv)
{
    struct timeval start;
    struct timeval end;

    float done;

    gettimeofday(&start, NULL);

    int array[10];

    gettimeofday(&end, NULL);

    FILE *fptr1 = fopen(argv[1], "rb");
    FILE *fptr2 = fopen(argv[2], "wb");

    fread(array, sizeof(int)*10, 1, fptr1);


    sortNum(array, 0, 9);

    printf("After sorting: \n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
        printf("\n");
    }

    fread(array, sizeof(int)*10, 1, fptr2);

    done = (end.tv_sec - start.tv_sec) + 1e-6*(end.tv_usec - start.tv_usec);
    printf("Time taken: %f\n", done);

    return 0;

}