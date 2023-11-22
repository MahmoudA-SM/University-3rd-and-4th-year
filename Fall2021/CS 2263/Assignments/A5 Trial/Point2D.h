#ifndef POINT2D_H
#define POINT2D_H
#include <stdio.h>
#include <math.h>
typedef struct point2d
{
        double x;
        double y;

}Point2D;

Point2D* mallocPoint2D();

void freePoint2D(Point2D* pPtThis);

Point2D* createPoint2D(double x, double y);

void setPoint2D(Point2D* pPtThis, double x, double y);

void setXPoint2D(Point2D* pPtThis, double x);

double getYPoint2D(Point2D* pPtThis);

Point2D* scanPoint(FILE* pFin);

double getDistancePoint2D( Point2D* ptThis, Point2D* pPtThat);

Point2D *copyPoint2D(Point2D *pThis);
#endif