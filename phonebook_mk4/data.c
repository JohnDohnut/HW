
#include <data.h>

data_s* data_t_init(){
	data_t* data = malloc(sizeof(data_t));
	data->file = file_t_init();
	data->list = doublylinked_list_init();
}
