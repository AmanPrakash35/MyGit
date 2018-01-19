// file copy -- char by char
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *srcpath = "/home/sunbeam/hive.txt";
	char *destpath = "/home/sunbeam/hive1.txt";
	FILE *fs, *fd;
	int ch;
	fs = fopen(srcpath, "r");
	if(fs == NULL)
	{
		perror("fopen() failed");
		exit(1);
	}
	fd = fopen(destpath, "w");
	if(fd == NULL)
	{
		perror("fopen() failed");
		fclose(fs);
		exit(2);
	}
	while( (ch=fgetc(fs)) != EOF )
	{
		//putchar(ch);
		fputc(ch, fd);
	}
	printf("File copied.\n");
	fclose(fd);
	fclose(fs);
	return 0;
}


/*
// file read program
int main()
{
	char *srcpath = "/home/sunbeam/hive.txt";
	FILE *fs;
	int ch;
	fs = fopen(srcpath, "r");
	if(fs == NULL)
	{
		perror("fopen() failed");
		exit(1);
	}
	while( (ch=fgetc(fs)) != EOF )
	{
		putchar(ch);
	}
	fclose(fs);
	return 0;
}
*/

