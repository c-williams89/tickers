#include <stdlib.h>
#include <stdio.h>

long get_file_size(const char file[])
{
	/*
	 * Gets and returns file size to use when reading entire file in main.
	 * closes the file so the pointer is reset to beginning of file next
	 * time it is opened.
	 */
	FILE *fp = fopen(file, "r");
	if (!fp) {
		perror("Could not open file: 'tickers.txt'\n");
		exit(1);
	}
	fseek(fp, (long)0, SEEK_END);
	long file_size = ftell(fp);
	fclose(fp);
	return file_size;
}