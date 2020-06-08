
#include "data.h"

data_t* data_t_init(){
	data_t* data = malloc(sizeof(data_t));
	data->list = doublylinked_list_init();
}
void data_append_node(data_t* data,node_t* node){	

	doublylinked_append_node(data->list, node);
	
}
long unsigned int data_size_of_node(){
	return doublylinked_size_of_node();
}

node_t* data_search_name(data_t* data,char BUFFER[]){
	return doublylinked_search_name(data->list, BUFFER);
}

node_t* data_search_email(data_t* data,char BUFFER[]){

	return doublylinked_search_email(data->list,BUFFER);
}
node_t* data_search_phone_number(data_t* data,char BUFFER[]){
	return doublylinked_search_phone_number(data->list,BUFFER);
}

void data_delete_node(data_t* data, char BUFFER[]){

	node_t* node = doublylinked_buffer_to_node(BUFFER);
	doublylinked_delete_node(data->list,node);

}
void data_print_data(data_t* data){
	doublylinked_print_list(data->list);
}
data_t* data_t_release(data_t* data){
	doublylinked_release(data->list);
	free(data);
}

node_t* data_buffer_to_node(char BUFFER[]){
	return doublylinked_buffer_to_node(BUFFER);
}
void data_print_list(data_t* data){
	doublylinked_print_list(data-> list);
}


node_t* data_get_head_node(data_t* data){
	return doublylinked_get_head_node(data->list);
}
node_t* data_get_next_node(data_t* data){
	return doublylinked_get_next_node(data->list);
}
node_t* data_create_node_with_data(char NAME[], char EMAIL[], char PHONE_NUMBER[]){
	return doublylinked_create_node_with_data(NAME,EMAIL,PHONE_NUMBER);
}













