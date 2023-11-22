#include "myUtil.h"
#include "myUtils.c"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 11;
    int num2 = 5;

    printf("The smaller number is: %d\n", min(num1, num2));
    printf("The larger number is: %d\n", max(num1, num2));
}