#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"
#include "Point2D.h"
#include "BRModule.h"
#include "PointListModule.h"
int main(int argc, StringList argv)
{
    FILE *f = fopen(argv[1], "r");
    int size;
    fscanf(f, "%d", &size);
    int i;
    for (i = 0; i < size; i++)
    {
        int inElements;
        fscanf(f, "%d", &inElements);
        BusRoute* br = mallocBusRoute(inElements);
        PointList *Plist;
        int j;
        String routeName;
        for (j = 0; j < inElements; j++)
        {
            Point2D *pointP = scanPoint(f);
            printf("(%lf, ", pointP->x);
            printf("%lf)", pointP->y);
            printf("\n");
            setPointinList(Plist, *pointP, j);
            point(br,*(pointP+j),j);
        }
    }
    FILE* studentFile = fopen(argv[3], "r");
    // for (i = 0; i < size; i++)
    // {
    //     Point2D* stuPoint = scanPoint(studentFile);

    // }
    return EXIT_SUCCESS;
}