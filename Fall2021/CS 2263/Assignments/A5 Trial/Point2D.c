#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point2D.h"

Point2D *mallocPoint2D()
{
        Point2D *pPt;
        pPt = (Point2D *)malloc(sizeof(Point2D));
        if (pPt == (Point2D *)NULL)
        {
                return NULL;
        }
        else
        {
                return pPt;
        }
}

void freePoint2D(Point2D *pPtThis)
{
        free(pPtThis);
}

Point2D *createPoint2D(double x, double y)
{
        Point2D *pt;
        pt = mallocPoint2D();
        pt->x = x;
        pt->y = y;
        return pt;
}

void setPoint2D(Point2D *pPtThis, double x, double y)
{
        pPtThis->x = x;
        pPtThis->y = y;
}

void setXPoint2D(Point2D *pPtThis, double x)
{
        pPtThis->x = x;
}

double getYPoint2D(Point2D *pPtThis)
{
        return pPtThis->y;
}

Point2D *scanPoint(FILE *pFIn)
{
        Point2D *pPtThis;
        double x;
        double y;
        int iNRead;
        iNRead = fscanf(pFIn, "%lf %lf", &x, &y);
        if (iNRead != 2)
                printf("Error");
                return (Point2D *)NULL;
        pPtThis = createPoint2D(x, y);
        return pPtThis;
}

double getDistancePoint2D(Point2D *pThis, Point2D *pThat)
{
        double xd = pow((pThis->x - pThat->x), 2);
        double yd = pow((pThis->y - pThat->y), 2);
        return sqrt(xd + yd);
}
Point2D *copyPoint2D(Point2D *pThis)
{
        Point2D *copy = mallocPoint2D();
        copy->x = pThis->x;
        copy->y = pThis->y;
        return copy;
}