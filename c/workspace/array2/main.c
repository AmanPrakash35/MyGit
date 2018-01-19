#include <stdio.h>

void print_arr(int a[][4], int r, int c);

int main()
{
	int arr[3][4] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 10, 20, 30};
	int (*ptr)[4];
	//ptr = &arr[0];
	ptr = arr;
		// *(*(ptr+i)+j) --> ptr[i][j]
	printf("%d\n", *(*(ptr+1)+2));
	printf("%d\n", (*(ptr+1))[2]);
	printf("%d\n", ptr[1][2]);
	print_arr(arr, 3, 4);
	return 0;
}

//void print_arr(int a[][4], int r, int c)
void print_arr(int (*a)[4], int r, int c)
{
	int i, j;
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}

