#include <stdio.h>

int isFib(int num)
{
    int num1;
    int num2;
    int num3;

    if((num == 0) || (num == 1))
    {
        printf("1"); //is a fibonacci number
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
            printf("1"); //is a fibonacci number
        }

        else
        {
            printf("0"); //not a fibonacci number
        }
    }
}