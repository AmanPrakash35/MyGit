#include <stdio.h>

int main()
{
	char *p = "abcd";
	printf("p = %p\n", p);
	*p = 'x';
	puts(p);
	return 0;
}
