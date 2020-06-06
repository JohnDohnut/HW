#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <doublylinked.h>

typedef struct file_s file_t;

struct file_s{/** struct to manage file*/
	int FD;	/**FD of opened db file*/
}

file_s* file_s_init(); /** init file_s**/
int file_db_open(file_t* file int argc);/**open file with given main param as an option*/
int file_db_close(file_t* file);	/**close given file with FD file->FD*/
int file_s_destroy(file_s* file);	/**release struct file_s*/

