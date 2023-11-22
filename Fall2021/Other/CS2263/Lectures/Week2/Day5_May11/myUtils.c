#include "myUtil.h"

int min(int x1, int x2)
{
    if(x1 > x2)
    {
        return x2;
    }
    else
    {
        return x1;
    }
}

int max(int x1, int x2)
{
    if(x1 > x2)
    {
        return x1;
    }
    else
    {
        return x2;
    }
}