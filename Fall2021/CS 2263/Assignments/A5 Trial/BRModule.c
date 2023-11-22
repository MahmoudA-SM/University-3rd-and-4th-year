#include <stdio.h>
#include <stdlib.h>
#include "Point2D.h"
#include "BRModule.h"

BusRoute* mallocBusRoute(int numStops)
{
        BusRoute* br = (BusRoute*)malloc(sizeof(BusRoute));
        br->pList = *mallocPointList(numStops);
        br->numStops = numStops;
        return br;
}

void point(BusRoute* br, Point2D point, int i)
{
        setPointinList(&br->pList, point, i);
}


Point2D* getPoint(BusRoute* br, int i)
{
        Point2D* p = getElementPointList(&br->pList, i);
        return p;
}