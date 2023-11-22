#include "Point2D.h"
#include "Strings.h"
#include "StudentModule.h"
#include <stdio.h>
#include <stdlib.h>


Student* createStudentObject(String studentName, Point2D studentLocation)
{
        Student* student = (Student*)malloc(sizeof(Student));
        student->studentName = studentName;
        student->studentLocation = studentLocation;
        return student;
}