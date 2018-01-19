#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, max, *ptr;
	printf("how many elements : ");
	scanf("%d", &n);
	ptr = (int*) malloc(n * sizeof(int));
	printf("enter numbers : ");
	for(i=0; i<n; i++)
		scanf("%d", &ptr[i]);
	max = 0;
	for(i=0; i<n; i++)
	{
		if(ptr[i] > max)
			max = ptr[i];
	}
	printf("max num : %d\n", max);
	free(ptr);
	ptr = NULL;
	return 0;
}
