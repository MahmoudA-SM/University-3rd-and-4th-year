#include <stdlib.h>
#include <stdio.h>

int remainder(int n, int d)
{
    if (n < d)
    {
        return n;
    }
    else
    {
        return remainder ((n - d), d);
    }
}

int main()
{
    int dividend; //المقسوم
    int divisor;  //المقسوم عليه
    printf("Enter the dividend: \n");
    scanf("%d", &dividend);
    printf("Enter the divisor: \n");
    scanf("%d", &divisor);
    printf("Remainder of dividing the dividend by the divisor: %d\n" ,remainder(dividend, divisor));
    return EXIT_SUCCESS;
}