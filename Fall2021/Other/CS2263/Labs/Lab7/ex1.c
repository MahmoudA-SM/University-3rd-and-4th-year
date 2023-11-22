#include <stdio.h>
#include <stdlib.h>


void sortingThis(int arr[], int n)
{  
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


void printArr(int arr[], int var)
{
    for(int i = 0; i < var; i++)
    {
        printf("%d\n", arr[i]);
        printf("\n");
    }
}


int main(int argc, char* argv[])
{
    int arr[] = {56, 45, 11, 23, 47, 54, 2, 99};
    int arrLength = sizeof(arr)/sizeof(arr[0]);

    sortingThis(arr, arrLength);

    printf("The sorted array is: \n");

    printArr(arr, arrLength);

    return 0;
}