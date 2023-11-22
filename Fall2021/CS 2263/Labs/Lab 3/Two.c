#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    int i = 0;
    int *arrp = arr;
    while (i <= 6)
    {
      printf("%d\t%d\t\t%p\t\t%d\n\n", i, arr[i],&arr[i], *arrp++);

      i++;
    }
    return EXIT_SUCCESS;
}
