#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"
#include "Point2D.h"
#include "PointList.h"
int main(int argc, StringList argv)
{
    FILE *f = fopen(argv[1], "r");
    int size;
    fscanf(f, "%d", &size);
    // printf("%d", size);

    // get the number of bus stops on every route
    int inElements;
    fscanf(f, "%d", &inElements);
    PointList *Plist;
    Plist->length = inElements;
    // printf("%d", Plist->length);

    int j;
    String routeName;
    for (j = 0; j < inElements; j++)
    {
        Point2D *pointP = fscanfPoint2D(f);
        printf("(%lf, ", pointP->x);
        printf("%lf)", pointP->y);
        printf("\n");
        setElementPointList(Plist, *pointP, j);
    }
    // routeName = fgetfString(f, terminators);
    // printf("%s", routeName);

    return EXIT_SUCCESS;
}