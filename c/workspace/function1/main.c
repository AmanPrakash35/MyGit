#include <stdio.h>
int fact(int n);
int main()
{
	int a, b;
	printf("enter number : ");
	scanf("%d", &a);
	b = fact(a);
	printf("result : %d\n", b);
	return 0;
}

int fact(int n)
{
	int i, r=1;
	for (i = 1; i <= n; ++i)
		r = r * i;
	return r;
}

