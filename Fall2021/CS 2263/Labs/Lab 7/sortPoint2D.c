#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct point2d
{
    double x;
    double y;

} Point2D;


typedef double (*compare)(Point2D pointOne, Point2D pointTwo);


Point2D *mallocPoint2DArray(int length)
{
    Point2D *point = (Point2D *)malloc(sizeof(Point2D) * length);
    return point;
}


double comparePoints2D(Point2D pointOne, Point2D pointTwo)
{
    return pointOne.x - pointTwo.x;
}


void freePoint2D(Point2D *point)
{
    free(point);
}


void sort(Point2D *array, int length, compare comp)
{
    int i, j;
    Point2D temp;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (comp(array[j], array[i]) < 0)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return EXIT_FAILURE;
    }

    int max = atoi(argv[1]);

    Point2D *point2dArray = mallocPoint2DArray(max);
    int i;
    for (i = 0; i < max; i++)
    {
        Point2D point;
        point.x = rand() / (double)10000;
        point.y = rand() / (double)10000;
        point2dArray[i] = point;
    }

    sort(point2dArray, max, comparePoints2D);

    for (i = 0; i < max; i++)
    {
        printf("(%lf,%lf)\n", point2dArray[i].x, point2dArray[i].y);
    }

    freePoint2D(point2dArray);

    return EXIT_SUCCESS;
}