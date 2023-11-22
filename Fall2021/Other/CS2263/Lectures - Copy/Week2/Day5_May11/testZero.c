#include "zero.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int a = 4;
    printf("The value of the address is: %d \n", a);

    zero(&a);
    printf("The new value of the address is: %d \n", a);
}