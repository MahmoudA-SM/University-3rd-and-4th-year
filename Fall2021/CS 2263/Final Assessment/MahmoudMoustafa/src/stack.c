#include <stdlib.h>
#include <stdio.h>
int multiply(int a, int b);
int sum (int c, int d);
int main(){
    int x = 5;
    int y = 7;
    int multandsum = sum(x,y);
    return EXIT_SUCCESS;
}

int multiply(int a, int b){
    return a*b;
}
int sum(int c, int d){
    return (c+d) + multiply(c,d);
}
