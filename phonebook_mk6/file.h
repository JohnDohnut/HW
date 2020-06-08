#pragma once
#include "doublylinked.h"

typedef struct file_s file_t;

struct file_s{/** struct to manage file*/
	int FD;	/**FD of opened db file*/
};

file_t* file_t_init(); /** init file_t**/
int file_db_open(file_t* file, int option);/**open file with given main param as an option*/
int file_db_close(file_t* file);	/**close given file with FD file->FD*/
int file_t_release(file_t* file);	/**release struct file_t*/
int file_read_db(file_t* file,char BUFFER[],long unsigned int node_size);
int file_write_db(file_t* file, char BUFFER[],long unsigned int buffer_size);
int file_get_FD(file_t* file);
