#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {MAX_CO_SIZE = 500, MAX_SYM_SIZE = 5, MAX_NO_CO = 11};

typedef struct company {
        char symbol[5];
        char co_name[50];
} company;

long get_file_size(char[]);

void read_parse_file();

void create_companies ();

int main(void)
{
        company co_list[MAX_NO_CO];
        char file[] = "./tickers.txt";
        long file_size = get_file_size(file);
        printf("File size: %ld\n", file_size);

        FILE *fp;
        fp = fopen(file, "r");
        char *tmp;
        char curr_co[MAX_CO_SIZE];

        int i = 0;
        while (fgets(curr_co, file_size, fp))
        {
                curr_co[strlen(curr_co) - 1] = '\0';
                create_companies(curr_co, &co_list[i]);
                i++;

        }
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

void create_companies (char *curr_co, company * co_list) {
        char *tmp;

        tmp = strsep(&curr_co, ": ");
        strncpy(co_list->symbol, tmp, sizeof(co_list->symbol));
        printf("%s\n", co_list->symbol);
        tmp = strsep(&curr_co, "\n");
        strncpy(co_list->co_name, tmp, sizeof(co_list->co_name));
        printf("%s\n", co_list->co_name);
       
}

void read_parse_file()
{
	FILE *fp;
	fp = fopen("./tickers.txt", "r");
        char *curr_co;
        char *tmp;
        company co_list[MAX_NO_CO];

        int i = 0;
        while (fgets(curr_co, MAX_CO_SIZE, fp))
        {
                curr_co[strlen(curr_co) - 1] = '\0';

                tmp = strsep(&curr_co, ":");
                printf("%s\n", tmp);
                // co_list[i];


                printf("%s\n", curr_co);
                i++;

        }
}
