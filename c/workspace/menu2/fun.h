#ifndef FUN_H_
#define FUN_H_

typedef enum
{
	EXIT, ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION
}menu_t;

menu_t show_menu();
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);

typedef void (*mathfn_t)(int,int);

#endif /* FUN_H_ */
