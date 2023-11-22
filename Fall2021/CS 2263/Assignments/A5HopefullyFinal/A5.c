#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"
#include "Point2D.h"
#include "BusRoute.h"
#include "PointList.h"
int main(int argc, StringList argv)
{
    FILE *f = fopen(argv[1], "r");
	char terminators[2];
	int size;
	terminators[0] = EOF;
	terminators[1] = '\n';
    fscanf(f, "%d", &size);
	
	BusRoute busses[size];
	
	int j;
	char* name;
	char* nameIter = name;
	int inElements;
	for(j=0; j<size; j++){
		BusRoute newBus;
		busses[j]=newBus;
		fscanf(f, "%d", &inElements);
		PointList *Plist = mallocPointList(inElements);
		Plist->length = inElements;

		int i;
		double x, y;
		for (i = 0; i < inElements; i++)
		{
			
			fscanf(f, "%lf", &x);
			fscanf(f, "%lf", &y);
			Point2D* pointP = createPoint2D(x,y);
			setElementPointList(Plist,*pointP,i);
		//	printf("%lf\t", pointP->x);
		//	printf("%lf", pointP->y);
		//	printf("\n");
			addPoint(&busses[j], *pointP, i);
		}
		name = getfString(f,terminators);
		(busses+j)->routeName = name;
		(busses+j)->numStops = inElements;
		(busses+j)->pList = *Plist;
		
	}
	

	int k;
	for(k=0; k<=size; k++){
		int l;
		for(l=0; l< (busses+k)->numStops; l++){
			//printf("%d\t%d\n",(busses+k)->numStops , l);
			printf("%lf\t",getPoint(busses+k, l)->x);
			printf("%lf\n",getPoint(busses+k, l)->y);
			//printf("%d\n",(busses+k)->numStops);
		}	
		//printf("hey\n");
	}
	
		
	
    return EXIT_SUCCESS;
}
