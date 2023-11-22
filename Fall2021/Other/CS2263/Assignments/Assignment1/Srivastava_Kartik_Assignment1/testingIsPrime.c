#include "isPrime.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int number;

    printf("Enter a number:");
    scanf("%d", &number);

    isPrime(number);
    return 0;
}