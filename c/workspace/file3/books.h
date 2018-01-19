#ifndef BOOKS_H_
#define BOOKS_H_

#define DB_FILE "library.db"

typedef struct book
{
	int id;
	char name[20];
}book_t;

void scan_book(book_t *b);
void print_book(book_t *b);

void add_book();
void display_books();
void edit_book();

#endif /* BOOKS_H_ */
