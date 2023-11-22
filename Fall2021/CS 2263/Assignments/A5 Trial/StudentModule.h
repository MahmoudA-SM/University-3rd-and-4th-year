#ifndef STUDENTMODULE_H
#define STUDENTMODULE_H
#include <stdio.h>
#include "Point2D.h"
#include "Strings.h"
typedef struct student
{
        Point2D studentLocation;
        String studentName; 
} Student;
Student* createStudentObject(String studentName, Point2D studentLocation);
#endif