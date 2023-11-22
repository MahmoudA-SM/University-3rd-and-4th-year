#include "isFib.h"
#include "isPrime.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1;
    int x2;
    int i;

    printf("Enter 2 integers: \n");
    scanf("%d%d", &x1, &x2);
    printf("\n");

    printf("Fibonacci primes are: \n");
    for(i = x1; i <= x2; i++)
    {
        if(isFib(i) == 0)
        {
            if(isPrime(i) == 1)
            {
                printf("%d\n", i);
            }
        }
    }
}