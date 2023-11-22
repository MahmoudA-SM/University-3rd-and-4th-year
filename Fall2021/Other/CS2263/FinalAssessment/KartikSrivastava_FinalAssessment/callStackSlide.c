#include <stdio.h>
#include <stdlib.h>

int factorialFunc(int num)
{
    if(num == 1)
    {
        return 1;
    }
    else
    {
        return num*factorialFunc(num-1);
    }
}

int main()
{
    printf("%i\n", factorialFunc(3));
    
    return EXIT_SUCCESS;
}

