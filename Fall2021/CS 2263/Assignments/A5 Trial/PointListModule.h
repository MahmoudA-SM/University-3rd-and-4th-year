#ifndef POINTLISTMODULE_H
#define POINTLISTMODULE_H
#include "Point2D.h"
#include <stdlib.h>
typedef struct pointlist{
        Point2D* pList;
        int length;
} PointList;
PointList* mallocPointList(int iNElements);
void freePointList(PointList* pList);
int setPointinList(PointList* pList, Point2D point, int index);
Point2D* getPointfromList(PointList* pList, int index);
#endif