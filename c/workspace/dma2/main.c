#include <stdio.h>
#include <stdlib.h>

int** alloc_matrix(int rows, int cols)
{
	int i, **ptr = (int**)malloc(rows * sizeof(int*));
	for(i=0; i<rows; i++)
		ptr[i] = (int*) malloc(rows * sizeof(int));
	return ptr;
}

void free_matrix(int** ptr, int rows)
{
	int i;
	for(i=0; i<rows; i++)
		free(ptr[i]);
	free(ptr);
}

void scan_matrix(int** ptr, int rows, int cols)
{
	int i, j;
	printf("input matrix (%dx%d) : ", rows, cols);
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			scanf("%d", &ptr[i][j]);
	}
}

void print_matrix(int** ptr, int rows, int cols)
{
	int i, j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			printf("%d\t", ptr[i][j]);
		printf("\n");
	}
}

void add_matrix(int **m1, int **m2, int **res, int rows, int cols)
{
	int i, j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
			res[i][j] = m1[i][j] + m2[i][j];
	}
}

int main()
{
	int rows, cols, **mat1, **mat2, **res;
	printf("enter num of rows and cols : ");
	scanf("%d%d", &rows, &cols);
	mat1 = alloc_matrix(rows, cols);
	mat2 = alloc_matrix(rows, cols);
	res = alloc_matrix(rows, cols);
	scan_matrix(mat1, rows, cols);
	scan_matrix(mat2, rows, cols);
	add_matrix(mat1, mat2, res, rows, cols);
	print_matrix(res, rows, cols);
	free_matrix(mat1, rows);
	free_matrix(mat2, rows);
	free_matrix(res, rows);
	return 0;
}
