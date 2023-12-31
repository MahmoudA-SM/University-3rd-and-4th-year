#ifndef BUSROUTE_H
#define BUSROUTE_H

#include <stdio.h>
#include "Point2D.h"
#include "PointList.h"
#include "Strings.h"

typedef struct busroute 
{
        String routeName;
        PointList pList;
        int numStops;
} BusRoute;

BusRoute* mallocBusRoute(int numStops);

void addPoint(BusRoute* route, Point2D point, int n);

Point2D* getPoint(BusRoute* route, int n);


#endif