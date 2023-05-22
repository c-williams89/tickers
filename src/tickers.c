#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

enum { MAX_CO_SIZE = 100, MAX_SYM_SIZE = 5, MAX_NO_CO = 10 };

typedef struct company {
	char symbol[5];
	char co_name[50];
} company;

long get_file_size(char[]);

void create_companies();

void print_ticker(company co_list[]);

int main(void)
{
	company co_list[MAX_NO_CO] = { 0 };
	char file[] = "./tickers.txt";
	long file_size = get_file_size(file);

	FILE *fp;
	fp = fopen(file, "r");
	char curr_co[MAX_CO_SIZE];

	int i = 0;
	while (fgets(curr_co, file_size, fp)) {
		curr_co[strlen(curr_co)] = '\0';
		create_companies(curr_co, &co_list[i]);
		i++;
	}
        fclose(fp);

	print_ticker(co_list);

	// read_parse_file();
}

long get_file_size(char file[])
{
	FILE *fp = fopen(file, "r");
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
        bool co_found;

	printf("Enter a symbol to search by: ");
	fgets(symbol, MAX_SYM_SIZE, stdin);

	nl_loc = strcspn(symbol, "\n");
	symbol[nl_loc] = '\0';

	for (int i = 0; i < MAX_NO_CO; ++i) {
                co_found = false;
		if ((strncmp(co_list[i].symbol, symbol, sizeof(symbol)) == 0)) {
			printf("%s: %s\n\n", co_list[i].symbol, co_list[i].co_name);
                        co_found = true;
                        break;
		}
	}
        if (!co_found) {
                printf("No company found with provided symbol\n");
        }
}
