
#include <data.h>

data_s* data_t_init(){
	data_t* data = malloc(sizeof(data_t));
	data->list = doublylinked_list_init();
}
void data_add_node(data_s* data,char BUFFER[]){	

	doublylinked_append_node(data->list, doublylinked_buffer_to_node(BUFFER));
	
}
long unsigned int data_size_of_node(){
	return doublylinked_size_of_node();
}

node_t* data_search_name(data_s* data,char BUFFER[]){
	return doublylinked_search_name(data->list, BUFFER);
}

node_t* data_search_name(data_s* data,char BUFFER[]){

	return doublylinked_search_email(data->list,BUFFER);
}
node_t* data_search_name(data_s* data,char BUFFER[]){
	return doublylinked_search_phone_number(data->list,BUFFER);
}

void data_delete_node(data_s* data, void* BUFFER){

	node_t* node = node_buffer_to_node(BUFFER);
	doublylinked_delete_node(data->list,node);

}
void data_print_data(data_s* data){
	doublylinked_print_list(data->list);
}
data_t* data_t_destroy(data_t* data){}

