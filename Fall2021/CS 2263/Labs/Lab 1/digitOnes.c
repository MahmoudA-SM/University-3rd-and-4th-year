#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * * argv)
{
   int value; 
   int iErr;
   int counter;
   printf("Value to examine: ");
   iErr = scanf("%d", &value);
   if (iErr != 1){
       printf("Unable to read the value\n");
   }
   if (value < 1)
   {
       return EXIT_FAILURE;
   }
   else
   {
       counter = 0;
       while (value > 0)
       {
           if (value % 2 == 1){
               counter++;
           }
           value = value / 2;
       }
       printf("Number of ones: %d\n", counter);
   }
    return EXIT_SUCCESS;
}