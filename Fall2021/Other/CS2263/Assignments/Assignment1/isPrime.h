#include <stdio.h>
int isPrime(int num)
{
    int i;
    int var = 0;

    for(i = 2; i <= num/2; i++)
    {
        if(num % i ==0)
        {
            var = 1;
            break;
        }
    }

    if(num == 1)
    {
        //printf("1 is neither prime, not composite\n");
    }
    
    else
    {
        if(var == 0)
        {
            return 1;
            //printf("The number is prime\n");
        }
        else
        {
            //printf("The number is not prime\n");
        }
    }

}

