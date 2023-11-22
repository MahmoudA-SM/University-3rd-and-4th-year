#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point.c"


int main(int argc, char const **argv)
{
    if(argc != 2)
    {
        printf("%s : %s\n", argv[0], "<number of points>");

        return EXIT_FAILURE;
    }

    int var = atoi(argv[1]);

    Point* pPt = mallocPoint();

    for(int i = 0; i < var; i++)
    {
        pPt->id = i;
        pPt->x = rand()/(float)10000;
        pPt->y = rand()/(float)10000;
        putw(var, stdout);

        fwritePoint(stdout, pPt);
    }

    freePoint(pPt);

    fprintf(stderr, "Binary file made successfully. \n");

    return EXIT_SUCCESS;
}