typedef struct point2d
{
    double x;
    double y;
} Point2D;
Point2D *mallocPoint2D();
void freePoint2D(Point2D *pThis);
Point2D *createPoint2D(double x, double y);
void setPoint2D(Point2D *pPt, double x, double y);
Point2D *copyPoint2D(Point2D *pThis);
double getXPoint2D(Point2D *pThis);
double getYPoint2D(Point2D *pThis);
double getDistancePoint2D(Point2D *pThis, Point2D *pThat);
