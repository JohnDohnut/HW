#pragma once
#include "doublylinked.h"

typedef struct data_s data_t;

struct data_s{/** struct to manage data*/
	doublylinked_t* list;
};


data_t* data_t_init();
void data_append_node(data_t* data, node_t* node);
long unsigned int data_size_of_node();
node_t* data_search_name(data_t* data,char BUFFER[]);
node_t* data_search_email(data_t* data,char BUFFER[]);
node_t* data_search_phone_number(data_t* data,char BUFFER[]);
void data_delete_node(data_t* data, char BUFFER[]);
void data_print_data(data_t* data);
data_t* data_t_release(data_t* data);
node_t* data_buffer_to_node(char BUFFER[]);
void data_print_list(data_t* data);
