#include <stdio.h>

int isFib(int num)
{
    int num1;
    int num2;
    int num3;

    if((num == 0) || (num == 1))
    {
        return 0;
        //printf("The number is a fibonacci number \n"); 
    }

    else
    {
        num1 = 0;
        num2 = 1;
        num3 = num1+num2;

        while(num3 < num)
        {
            num1 = num2;
            num2 = num3;
            num3 = num1+num2;
        }

        if(num3 == num)
        {
            return 0;
            //printf("The number is a fibonacci number \n"); 
        }

        else
        {
            //printf("The number is not a fibonacci number \n"); 
        }
    }
}