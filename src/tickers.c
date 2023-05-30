#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include "../include/print_tickers.h"

#define INPUT_FILE "./data/tickers.txt"

long get_file_size(const char[]);

void create_companies(char *curr_co, company * co_list);

int main(void)
{
	system("clear");
	company co_list[MAX_NO_CO] = { 0 };
	const char file[] = INPUT_FILE;
	long file_size = get_file_size(file);

	FILE *fp;
	fp = fopen(file, "r");
	if (!fp) {
		perror("Could not open file: 'tickers.txt'\n");
		exit(1);
	}
	char curr_co[MAX_CO_SIZE];
	int i = 0, nl_loc = 0;
	while (fgets(curr_co, file_size, fp)) {
		nl_loc = strcspn(curr_co, "\n");
		curr_co[nl_loc] = '\0';
		create_companies(curr_co, &co_list[i]);
		i++;
	}
	fclose(fp);
	print_ticker(co_list);
}

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

void create_companies(char *curr_co, company * co_list)
{
	// Creates a single struct at respective co_list index
	char *tmp;
	tmp = strsep(&curr_co, ":");
	strncpy(co_list->symbol, tmp, sizeof(co_list->symbol));
	tmp = strsep(&curr_co, "\n");
	strncpy(co_list->co_name, tmp, sizeof(co_list->co_name));
}
