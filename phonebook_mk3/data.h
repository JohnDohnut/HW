#include "doublylinked.h"

typedef struct data_data_s{
	int FD;
	phonebook_column_s* HEAD;
	phonebook_column_s* CURRENT;
	phonebook_column_s* USER_INPUT_COLUMN;
	int PARAM_OPTION;
	char PARAM_DATA[];
	enum error_t ERROR;

}data_s;

data_s* data_data_s_init();
int data_handle_main_param(data_s* data);
int data_load_list_from_file(data_s* data);
int data_open_file(data_s* data);
void data_final(data_s* data);

