#include <stdlib.h>
#include <stdio.h>
int main(){
    FILE* f = fopen("writes.txt", "r");
    char s[4];
    fgets(s,10,f);
    printf("%s",s);
    fclose(f);
    return 0;
}