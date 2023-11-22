#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0, j = 0;
	int array [5] [5] = {
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11, 12, 13, 14, 15},
	{16, 17, 18, 19, 20},
	{21, 22, 23, 24, 25}
	};
	
	printf("Before changing the array\n");
	while (i < 5)
	{
		while(j < 5){
			printf("%d ", array[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
	i = 0;
	
	while (i < 5)
	{
		while (j < 5)
		{	
			array[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	printf("After changing\n");
	while (i < 5)
	{
		while(j < 5){
			printf("%d ", array[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
	return EXIT_SUCCESS;
}
//	for(int i = 0; i < rows; i++){
//		for(int j = 0; j < cols; j++){
//			array[i][j] = 0;
//		}
//	}
//	printf("Done changing");
//		for(int i = 0; i < rows; i++){
//			for(int j = 0; j < cols; j++){
//			printf(array[i][j]);	
//			}
//			
//		}
