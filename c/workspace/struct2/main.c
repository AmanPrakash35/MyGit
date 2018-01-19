#include <stdio.h>
#pragma pack(1)

struct test
{
	char c;
	int i;
};

int main()
{
	struct test t;
	printf("size : %d\n", sizeof(t));
	printf("&t : %p\n", &t);
	printf("&t.i : %p\n", &t.i);
	printf("&t.c : %p\n", &t.c);
	return 0;
}


