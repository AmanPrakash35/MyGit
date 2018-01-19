#include <stdio.h>
#include "fun.h"

int main()
{
	enum menu ch;
	int a, b;
	do
	{
		ch = show_menu();
		switch (ch)
		{
		case EXIT:
			printf("good bye!\n");
			break;
		case ADDITION:
			printf("enter two numbers : ");
			scanf("%d%d", &a, &b);
			add(a, b);
			break;
		case SUBTRACTION:
			printf("enter two numbers : ");
			scanf("%d%d", &a, &b);
			subtract(a, b);
			break;
		case MULTIPLICATION:
			printf("enter two numbers : ");
			scanf("%d%d", &a, &b);
			multiply(a, b);
			break;
		case DIVISION:
			printf("enter two numbers : ");
			scanf("%d%d", &a, &b);
			divide(a, b);
			break;
		}
	}while(ch!=EXIT);
	return 0;
}


