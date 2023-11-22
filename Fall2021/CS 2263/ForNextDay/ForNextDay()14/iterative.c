#include <stdio.h>
int fac2(int n)
{
    printf("Top of the stack: %p\n", &n);
    int val = 1;
    // printf("&val: %p\n", &val);
    if (n == 0)
    {
        val = 1;
        return val;
    }
    while (n > 0)
    {
        val *= n;
        n--;
        
    }
    
    return val;
}
int main(int argc, char *argv[])
{
    int x = 15;
    int f = fac2(x);
    printf("Bottom of the stack: %p\n", &x);  
    printf("%d\n", f); // RL1 
}
