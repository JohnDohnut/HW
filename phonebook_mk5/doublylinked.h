#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "node.h"

typedef struct doublylinked_s doublylinked_t;
struct doublylinked_s{	/**struct which contains head and tail node of list*/
	node_t* HEAD;	/**head node of list*/
	node_t* TAIL;	/**tail node of list, just in case.*/
};

doublylinked_t* doublylinked_list_init();
void doublylinked_destroy(doublylinked_t* list);

int doublylinked_append_node(doublylinked_t* list, node_t* node);

int doublylinked_delete_node(doublylinked_t* list, node_t* node);

node_t* doublylinked_search_name(doublylinked_t* list);

node_t* doublylinked_search_email(doublylinked_t* list);

node_t* doublylinked_search_phone_number(doublylinked_t* list);

long unsigned int doublylinked_size_of_node(){
	return node_size_of_node();
