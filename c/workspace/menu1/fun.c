#include <stdio.h>
#include "fun.h"

enum menu show_menu()
{
	enum menu choice;
	printf("\n\n0. EXIT\n1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\nEnter choice : ");
	scanf("%d", &choice);
	return choice;
}

void add(int a, int b)
{
	int res = a + b;
	printf("add result : %d\n", res);
}
void subtract(int a, int b)
{
	int res = a - b;
	printf("subtract result : %d\n", res);
}
void multiply(int a, int b)
{
	int res = a * b;
	printf("multiply result : %d\n", res);
}
void divide(int a, int b)
{
	int res = a / b;
	printf("divide result : %d\n", res);
}

