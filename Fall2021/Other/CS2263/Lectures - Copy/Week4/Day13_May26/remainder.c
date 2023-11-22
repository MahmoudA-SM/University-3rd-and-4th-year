#include <stdio.h>
#include <stdlib.h>


int rem(int n, int d)
{

    if(n >= d)
    {
        n = rem(n-d, d);
    }

    printf("%d\n", n);

    return n;
}


int main()
{
    int num1;
    int num2;

    printf("Enter 2 numbers: \n");
    scanf("%d %d", &num1, &num2);

    int answer = rem(num1, num2);

    printf("Remainder: %d\n", answer);

    return EXIT_SUCCESS;
}