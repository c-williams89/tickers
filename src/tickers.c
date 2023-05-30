#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include "../include/print_tickers.h"
#include "../include/create_companies.h"
#include "../include/get_file_size.h"

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