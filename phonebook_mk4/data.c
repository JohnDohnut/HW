
#include <data.h>

data_s* data_t_init(){
	data_t* data = malloc(sizeof(data_t));
	data->file = file_t_init();
	data->list = doublylinked_list_init();
}
data_s* data_open_db(data* data, int option){
	file_db_open(file,option);
}

