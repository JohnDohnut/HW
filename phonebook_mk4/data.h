#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <doublylinked.h>
#include <file.h>
typedef struct data_s data_t;

struct data_s{/** struct to manage data*/
	file_t* file;
	doublylinked_t* list;
}


data_s* data_t_init();
