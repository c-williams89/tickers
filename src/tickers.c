#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio_ext.h>

#define INPUT_FILE "./data/tickers.txt"
#define OUTPUT_FILE "./data/search_results"

enum { MAX_CO_SIZE = 64, MAX_SYM_SIZE = 8, MAX_NO_CO = 10 };

typedef struct company {
	char symbol[5];
	char co_name[50];
} company;

long get_file_size(const char[]);

void create_companies(char *curr_co, company * co_list);

void print_ticker(company co_list[]);

void write_to(char *co_to_print);

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
	char *tmp;
	tmp = strsep(&curr_co, ":");
	strncpy(co_list->symbol, tmp, sizeof(co_list->symbol));
	tmp = strsep(&curr_co, "\n");
	strncpy(co_list->co_name, tmp, sizeof(co_list->co_name));
}

void print_ticker(company co_list[])
{
	int nl_loc = 0;
	char symbol[MAX_SYM_SIZE] = { 0 };
	char co_to_print[MAX_CO_SIZE] = { 0 };
	bool co_found;
	while (true) {
		printf("Enter a symbol to search or 'Q' to quit: ");
		fgets(symbol, MAX_SYM_SIZE, stdin);
		nl_loc = strcspn(symbol, "\n");
		symbol[nl_loc] = '\0';
		for (int i = 0; symbol[i] != '\0'; ++i) {
			if (symbol[i] >= 'a' && symbol[i] <= 'z') {
				symbol[i] -= 32;
			}
		}
		if (strncmp(symbol, "Q", 1) == 0) {
			printf("\n\tExiting now. Goodbye\n");
			exit(0);
		} else {
			for (int i = 0; i < MAX_NO_CO; ++i) {
				co_found = false;
				if ((strncmp
				     (co_list[i].symbol, symbol,
				      sizeof(symbol)) == 0)) {
					snprintf(co_to_print, MAX_CO_SIZE,
						 "%s: %s\n",
						 co_list[i].symbol,
						 co_list[i].co_name);
					printf("\033[96m\033[1m\t%s\033[0m\n\n",
					       co_list[i].co_name);
					co_found = true;
					write_to(co_to_print);
					break;
				}
			}
			if (!co_found) {
				printf
				    ("\033[31m\033[1mNo company found with provided symbol\033[0m\n\n");
			}
		}
		__fpurge(stdin);
	};
}

void write_to(char *co_to_print)
{
	char output_file[] = OUTPUT_FILE;
	FILE *fp = fopen(output_file, "a");
	fwrite(co_to_print, sizeof(char), strlen(co_to_print), fp);
	fclose(fp);
}
