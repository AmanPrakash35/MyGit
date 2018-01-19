#include <stdio.h>

// declaration of "struct book" data type
struct book
{
	int id;
	char name[20];
	double price;
};

void print_book(struct book b);
void scan_book(struct book *b);
void print_books(struct book a[], int n);

int main()
{
	// declare struct variable
	struct book b1;
	// initialize each member of struct variable
	b1.id = 2;
	strcpy(b1.name, "exploring c");
	b1.price = 500.00;
	printf("%d %s %lf\n", b1.id, b1.name, b1.price);

	// declare and initailize struct variable
	struct book b2 = {1, "let us c", 430.00};
	struct book *p;
	p = &b2;
	printf("%d %s %lf\n", p->id, p->name, p->price);

	struct book b3;
	// pass struct to func - by address.
	scan_book(&b3);
	// pass struct to func - by value.
	print_book(b3);

	struct book arr[3];
	int i;		// arr[i] -- struct variable
	for(i=0; i<3; i++)
		scan_book(&arr[i]);
	print_books(arr, 3);
	return 0;
}

void scan_book(struct book *b)
{
	printf("enter id, name and price : ");
	scanf("%d%s%lf", &b->id, b->name, &b->price);
}
void print_book(struct book b)
{
	printf("print book : %d %s %lf\n", b.id, b.name, b.price);
}
void print_books(struct book a[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("print book : %d %s %lf\n", a[i].id, a[i].name, a[i].price);
}


