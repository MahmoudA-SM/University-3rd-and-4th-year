#include <stdlib.h>
#include <stdio.h>

// int Sigma(int k){
// int l;
// l = k - 1;
// if (k==0)
// return 0;
// else
// return (k + Sigma(l));
// }
int Sigma(int k)
{
    int l;
    l=k-1;
    while(l!=0){
        k=k+l;
        l=l-1;
    }
    return k;
}

int main(){
    int res,k = 10;
    res = Sigma(k);
    printf("%d", res); 
}