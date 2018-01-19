#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, rows, cols, **ptr;
	printf("enter num of rows and cols : ");
	scanf("%d%d", &rows, &cols);
	ptr = (int**)malloc(rows * sizeof(int*));
	for(i=0; i<rows; i++)
		ptr[i] = (int*) malloc(rows * sizeof(int));

	printf("input matrix (%dx%d) : ", rows, cols);
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			scanf("%d", &ptr[i][j]);
	}

	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			printf("%d\t", ptr[i][j]);
		printf("\n");
	}

	for(i=0; i<rows; i++)
		free(ptr[i]);
	free(ptr);
	return 0;
}
