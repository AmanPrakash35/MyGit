// file copy -- line by line
#include <stdio.h>
#include <stdlib.h>

/*
RUN:
	./file2 srcfilepath destfilepath
		argc --> 3
		argv[0] --> exe name i.e. file2
		argv[1] --> srcfilepath
		argv[2] --> destfilepath
*/

int main(int argc, char *argv[])
{
	FILE *fs, *fd;
	char line[128];
	if(argc != 3)
	{
		printf("wrong arguments.\n%s <srcpath> <destpath>\n", argv[0]);
		exit(3);
	}
	fs = fopen(argv[1], "r");
	if(fs == NULL)
	{
		perror("fopen() failed");
		exit(1);
	}
	fd = fopen(argv[2], "w");
	if(fd == NULL)
	{
		perror("fopen() failed");
		fclose(fs);
		exit(2);
	}

	while( fgets(line, sizeof(line), fs) != NULL )
	{
		fputs(line, fd);
	}

	printf("File copied.\n");
	fclose(fd);
	fclose(fs);
	return 0;
}

