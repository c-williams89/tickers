#include "../include/print_tickers.h"
#include <string.h>

void create_companies(char *curr_co, company * co_list)
{
	// Creates a single struct at respective co_list index
	char *tmp;
	tmp = strsep(&curr_co, ":");
	strncpy(co_list->symbol, tmp, sizeof(co_list->symbol));
	tmp = strsep(&curr_co, "\n");
	strncpy(co_list->co_name, tmp, sizeof(co_list->co_name));
}