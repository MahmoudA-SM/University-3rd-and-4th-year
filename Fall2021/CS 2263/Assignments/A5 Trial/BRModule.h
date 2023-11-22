#ifndef BRMODULE_H
#define BRMODULE_H
#include <stdio.h>
#include "Point2D.h"
#include "PointListModule.h"
#include "Strings.h"
typedef struct busroute 
{
        String routeName;
        PointList pList;
        int numStops;
} BusRoute;
BusRoute* mallocBusRoute(int numStops);
void point(BusRoute* route, Point2D point, int i);
Point2D* getPoint(BusRoute* route, int i);
#endif