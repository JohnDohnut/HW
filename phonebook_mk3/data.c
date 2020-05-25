#include "data.h"

void data_data_s_init(data_s* data){
	data -> FD = -1;
	data -> HEAD = NULL;
	data -> CURRENT = NULL;
	data -> USER_INPUT_COLUMN = NULL;
	data -> PARAM_OPTION -1;
	data -> PARAM_BUFFER = NULL;
	data -> ERROR = DEFAULT;
	
}

void data_handle_main_param(data_s* data, int argc, char* argv[]){
	if (argc < 3){
		if(atoi(argv[1]) != 5){
			printf("Need more parameter\n");
			data->ERROR = MAIN_PARAM_ERROR;
			return -1;
		}
	}
	else {
		data->PARAM_OPTION = atoi(argv[1]);
		data->PARAM_BUFFER = argv[2]; 
	}
	
}

int data_open_file(data_s* data){
	if(data->PARAM_OPTION > 0 && data->PARAM_OPTION < 4){
		data->FD = open("DB.bin",O_RDONLY);
	}
	else if(data->PARAM_OPTION == 4){
		data->FD = open("DB.bin",O_RDWR|O_TRUNC);
	}
	else if(data->PARAM_OPTION == 5){
		data->FD = open("DB.bin",O_WRONLY|O_APPEND);
	}
	if (data->FD ==-1)
		return -1;
	return 0;
}

int data_load_list_from_file(data_s* data){
	phonebook_column_s BUFFER[1];
	phonebook_column_s* NEW_COLUMN;
	memset(BUFFER,0,sizeof(phonebook_column_s);
	if(data->FD == -1){
		printf("file is not opened\n\n");
		data->ERROR = FILE_NOT_OPENED;
		return -1;	
	}
	while(read(data->FD,BUFFER,sizeof(phonebook_column_s))!=0){
		NEW_COLUMN = phonebook_column_init();
		phonebook_copy_column(BUFFER,NEW_COLUMN);
		data->CURRENT = doublylinked_list_append_node(data->CURRENT, NEW_COLUMN);
	}
	data->CURRENT = doublylinked_find_head_node(data->CURRENT);
	data->HEAD = data->CURRENT;
	printf("Database loaded\n\n");
	doublylinked_print_list(data->CURRENT);
	printf("\n\n");
	return 0;

}
int store_data_to_file(data_s* data){
	if(data->PARAM_OPTION == 5){
		write(data->FD, data->CURRENT, sizeof(phonebook_column_s));
		return 0;
	}
	else if (data->PARAM_OPTION == 4){
		data->CURRENT = data->HEAD;
		while(data->CURRENT != NULL){
			write(data->FD, data->CURRENT, sizeof(phonebook_column_s));
			data->CURRENT = data->CURRENT->NEXT;
		}
		return 0;
	}
	else{
		data->ERROR = WRITE_UNAVAILABLE;
		return -1;
	}
	
}
void data_final(data_s* data){
	close(data->FD);
	data->FD = -1;
	doublylinked_release_list(data->HEAD);
	data->CURRENT = NULL;
	return 0;
}


