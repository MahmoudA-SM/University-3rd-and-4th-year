#include <stdio.h>
#include <stdlib.h>

int fac2(int n) 
{
    int val = 1 ;
    if (n == 0) 
    {
        val = 1; 
        return val;
    }
    while (n > 0) 
    {
        val *= n; n --;
    }
    return val; 
}


int main(int argc, char * argv[]) 
{
    int x = 5;
    int f = fac2(x);
    printf("%d", f); // RL1
    printf("\n");
    printf("Address of number: %p\n", &x);
    printf("Address of factorial: %p\n", &f);
}