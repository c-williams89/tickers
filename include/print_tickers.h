#ifndef PRINT_TICKERS_H
#define PRINT_TICKERS_H
        #define MAX_CO_SIZE 64
        #define MAX_SYM_SIZE 8
        #define MAX_NO_CO 10
        // struct company;
        typedef struct company {
	        char symbol[5];
	        char co_name[50];
        } company;

        void print_ticker(company co_list[]);
#endif