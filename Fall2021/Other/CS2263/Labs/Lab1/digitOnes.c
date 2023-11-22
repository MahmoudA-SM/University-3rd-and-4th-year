#include <stdio.h>
#include <stdlib.h>
int main()
{
    int value;
    int iErr;

    printf("Value to examine: ");
    iErr = scanf("%d", &value);
    
    if(iErr != 1)
    {
        printf("Unable to read the value\n");
    }

    if(value <= 0)
    {
        printf("Invalid input");
        exit(0);
    }
    else
    {
        int numOnes = 0; 

        while(value > 0)
        {
             if(value & 1)
                numOnes++;

             value >>= 1;
        }
    
    printf("Number of ones: %d\n", numOnes);

    return EXIT_SUCCESS;
    }
}
    
    
   
 
