#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"
#include <string.h>

char *mallocString(int stringsize)
{
    char *pc = (char *)malloc(sizeof(char) * (stringsize + 1));
    if (pc == (char *)NULL)
    {
        return (char *)NULL;
    }
    return pc;
}

void freeString(char *s)
{
    free(s);
}

char *duplicateString(char *s)
{
    char *copy = mallocString(sizeof(s));
    if (copy == (char *)NULL)
    {
        return (char *)NULL;
    }
    strcpy(copy, s);
    return copy;
}
int fputString(FILE *pFOut, char *s)
{
    fprintf(pFOut, "%d %s",strlen(s)-1, s);
}
char* fgetString(FILE* pFIn)
{
  int length;
  fscanf(pFIn, "%d", &length);
  char *stringp = (char*) mallocString(sizeof(char) * length+2);

  fgets(stringp, length+2, pFIn); //for NULL
  int i;
  for (i = 1; i < length+2; i++){
    printf("%c", stringp[i]);
  }
  printf("\n");

  while(stringp[i]!= EOF){
    while (i <= length+2 )
    {
      fscanf(pFIn, "%d", &length);
      stringp = (char*) mallocString(sizeof(char) * length+2);
      fgets(stringp, length+3, pFIn);
      for (i = 1; i < length+2; i++){
        printf("%c", stringp[i]);
      }


    }
  }
  free(stringp);
  return stringp;

}
