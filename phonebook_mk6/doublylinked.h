#pragma once
#include "node.h"
typedef struct doublylinked_s doublylinked_t;
struct doublylinked_s{	/**struct which contains head and tail node of list*/
	node_t* HEAD;	/**head node of list*/
	node_t* TAIL;	/**tail node of list, just in case.*/
};

doublylinked_t* doublylinked_list_init();

void doublylinked_release(doublylinked_t* list);

int doublylinked_append_node(doublylinked_t* list, node_t* node);

int doublylinked_delete_node(doublylinked_t* list, node_t* node);

node_t* doublylinked_search_name(doublylinked_t* list, char NAME[]);

node_t* doublylinked_search_email(doublylinked_t* list, char EMAIL[]);

node_t* doublylinked_search_phone_number(doublylinked_t* list, char PHONE_NUMBER[]);

long unsigned int doublylinked_size_of_node();

void doublylinked_print_list(doublylinked_t* list);

long unsigned int doublylinked_size_of_node();

node_t* doublylinked_buffer_to_node(char BUFFER[]);

void doublylinked_print_node(node_t* node);

node_t* doublylinked_node_init();

node_t* doublylinked_create_node_with_data(char NAME[], char EMAIL[], char PHONE_NUMBER[]);

node_t* doublylinked_get_head_node(doublylinked_t* list);
