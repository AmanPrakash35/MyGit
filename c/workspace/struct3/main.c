#include <stdio.h>

/*
struct book
{
	int id;
	char name[20];
	double price;
	struct date
	{
		int day, month, year;
	} publish;
};
*/

struct date
{
	int day, month, year;
};
struct book
{
	int id;
	char name[20];
	double price;
	struct date publish;
};

int main()
{
	struct book b = { 1, "ABC", 100, {12, 12, 2000} };
	struct book *p = &b;
	printf("%d %s %lf %d-%d-%d\n", b.id, b.name, b.price,
		b.publish.day, b.publish.month, b.publish.year);
	printf("%d %s %lf %d-%d-%d\n", p->id, p->name, p->price,
		p->publish.day, p->publish.month, p->publish.year);
	return 0;
}
