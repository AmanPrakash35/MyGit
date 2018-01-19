#include <stdio.h>
#include "func.h"

int fact(int n)
{
	int i, r=1;
	for (i = 1; i <= n; ++i)
		r = r * i;
	return r;
}

int combn(int n, int r)
{
	int nf, rf, nrf, res;
	nf = fact(n);
	rf = fact(r);
	nrf = fact(n-r);
	res = nf / (rf * nrf);
	return res;
}

void pascal(int max)
{
	int n, r, res;
	for(n=0; n<=max; n++)
	{
		for(r=0; r<=n; r++)
		{
			res = combn(n, r);
			printf("%d\t", res);
		}
		printf("\n");
	}
}




