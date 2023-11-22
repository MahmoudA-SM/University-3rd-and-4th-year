#include <stdio.h>
#include <stdlib.h>

int isPrime(int num)
{
    int i;
  //  int i;
    int var = 0;

   // printf("Enter a number:");
   // scanf("%d", &num);

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
        printf("1 is neither prime, not composite");
    }
    
    else
    {
        if(var == 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

}

