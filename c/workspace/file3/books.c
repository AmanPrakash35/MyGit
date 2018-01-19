#include <stdio.h>
#include "books.h"

void scan_book(book_t *b)
{
	printf("enter book id and name : ");
	scanf("%d%s", &b->id, b->name);
}
void print_book(book_t *b)
{
	printf("%d\t%s\n", b->id, b->name);
}

void add_book()
{
	FILE *fp;
	book_t b;
	int n;
	scan_book(&b);

	fp = fopen(DB_FILE, "ab");
	if(fp == NULL)
	{
		perror("fopen() failed");
		return;
	}

	n = fwrite(&b, sizeof(book_t), 1, fp);
	printf("books added : %d\n", n);

	fclose(fp);
}
void display_books()
{
	book_t b;
	FILE *fp;
	fp = fopen(DB_FILE, "rb");
	if(fp == NULL)
	{
		perror("fopen() failed");
		return;
	}

	while( fread(&b, sizeof(book_t), 1, fp) > 0 )
	{
		print_book(&b);
	}

	fclose(fp);
}

void edit_book()
{
	FILE *fp;
	book_t b, t;
	int id;
	long size = sizeof(book_t);
	printf("enter id of book to be edited: ");
	scanf("%d", &id);

	//find book to be edited.
	fp = fopen(DB_FILE, "rb+");
	if(fp == NULL)
	{
		perror("fopen() failed");
		return;
	}
	while( fread(&b, sizeof(book_t), 1, fp) > 0 )
	{
		if(id == b.id)
		{
			printf("BOOK FOUND.\n");
			print_book(&b);
			//input new contents of that book.
			scan_book(&t);
			//overwrite the contents into file.
			fseek(fp, -size, SEEK_CUR);
			fwrite(&t, sizeof(book_t), 1, fp);
			break;
		}
	}
	fclose(fp);
}













