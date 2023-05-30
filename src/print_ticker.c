#define _GNU_SOURCE
#include <stdbool.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/print_tickers.h"

#define OUTPUT_FILE "./data/search_results"

static void write_to(char *co_to_print)
{
	char output_file[] = OUTPUT_FILE;
	FILE *fp = fopen(output_file, "a");
	fwrite(co_to_print, sizeof(char), strlen(co_to_print), fp);
	fclose(fp);
}

void print_ticker(company co_list[])
{
	int nl_loc = 0;
        size_t len = 0;
        char *symbol = NULL;
	// char symbol[MAX_SYM_SIZE] = { 0 };
	char co_to_print[MAX_CO_SIZE] = { 0 };
	bool co_found;
	while (true) {
		printf("Enter a symbol to search or 'Q' to quit: ");
                nl_loc = getline(&symbol, &len, stdin);
                printf("%ld\n\n", len);
		// fgets(symbol, MAX_SYM_SIZE, stdin);
		// nl_loc = strcspn(symbol, "\n");
		symbol[nl_loc - 1] = '\0';

		// loop to convert input to upper 
		for (int i = 0; symbol[i] != '\0'; ++i) {
			if (symbol[i] >= 'a' && symbol[i] <= 'z') {
				symbol[i] -= 32;
			}
		}
		if (strncmp(symbol, "Q", 1) == 0) {
			printf("\n\tExiting now. Goodbye\n");
			return;
		} else {
			for (int i = 0; i < MAX_NO_CO; ++i) {
				co_found = false;
				if ((strncmp
				     (co_list[i].symbol, symbol,
				      nl_loc) == 0)) {
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

