#include <stdlib.h>
#include <stdio.h>
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

void freePoint2D(Point2D *pThis)
{
    free(pThis);
}

Point2D *createPoint2D(double x, double y)
{
    Point2D *pt;
    pt = mallocPoint2D();
    pt->x = x;
    pt->y = y;
    return pt;
}

void setPoint2D(Point2D *pPt, double x, double y)
{
    pPt->x = x;
    pPt->y = y;
}

Point2D *copyPoint2D(Point2D *pThis)
{
    Point2D *copy = mallocPoint2D();
    copy->x = pThis->x;
    copy->y = pThis->y;
    return copy;
}

double getXPoint2D(Point2D *pThis)
{
    return pThis->x;
}

double getYPoint2D(Point2D *pThis)
{
    return pThis->y;
}

double getDistancePoint2D(Point2D *pThis, Point2D *pThat)
{
    double xd = pow((pThis->x - pThat->x), 2);
    double yd = pow((pThis->y - pThat->y), 2);
    return sqrt(xd + yd);
}