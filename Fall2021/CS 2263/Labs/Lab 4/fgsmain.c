#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"
int main(int argc, char* argv[])
{
      FILE *f = fopen("q2input.txt", "r");
      if (f == (FILE*)NULL)
      {
          printf("Error opening input.txt\n");
      }
      fgetString(f);
      free(f);
}
