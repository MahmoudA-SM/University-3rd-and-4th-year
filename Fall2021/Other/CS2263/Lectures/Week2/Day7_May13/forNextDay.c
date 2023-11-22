#include <stdio.h>
#include <stdlib.h>
#define ROW 2
#define COLUMN 3

int main()
{
    int row;
    int column;
    int arr[ROW][COLUMN] = {};
   
    int i;
    int j;

    for(i = 0; i < ROW; i++)
    {
        //printf("\n");

        for(j = 0; j < COLUMN; j++)
        {
            printf("%d", arr[i][j]);
        }

        printf("\n");
    }
}