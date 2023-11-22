#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char input[100000];
void fileopen(char *x[])
{
 int i;
 FILE *fp;
 char *iP = &input[0];
 fp = fopen(*(x+1),"r");
 while ((i = fgetc(fp))!= EOF)
 {
 *iP = i;
 iP++;
 }
 fclose(fp);
}
