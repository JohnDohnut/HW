#include "doublylinked.h"


doublylinked_t* doublylinked_list_init(){
	doublylinked_t* list = malloc(sizeof(doublylinked_t));
	memset(list,0x00,sizeof(doublylinked_t));
}
void doublylinked_release(doublylinked_t* list){
	node_t* curr_node;
	node_t* temp;
	curr_node = list->HEAD;
	while(curr_node != 0x00){
		temp=curr_node->NEXT;
		node_release(curr_node);
		curr_node=temp;
	}
	free(list);
}

int doublylinked_append_node(doublylinked_t* list, node_t* node){
	if(list->HEAD == 0x00){
		list->HEAD = node;
		list->TAIL = node;
	}
	if(list->TAIL == 0x00){
		write(1,"broken list",sizeof("broken list\n")); 
		return -1;
	}
	list->TAIL->NEXT = node;
	node->PREV = list->TAIL;
	node->NEXT = 0x00;
	list->TAIL = node;
	return 0;
}
int doublylinked_delete_node(doublylinked_t* list, node_t* node){
	node_t* curr_node = list->HEAD;
	if(node == list->HEAD){
		list->HEAD = list->HEAD->NEXT;
		list->HEAD->PREV = 0x00;
		node_release(curr_node);
	}
	else{
		while(curr_node!=0x00){
			if(curr_node == node){
				if(curr_node == list->TAIL){
					list->TAIL = curr_node->PREV;
					list->TAIL->NEXT = 0x00;
					node_release(curr_node);
					return 0;
				}
				else{
					node_t* prev_node = curr_node->PREV;
					node_t* next_node = curr_node->NEXT;
					prev_node->NEXT = next_node;
					next_node->PREV = prev_node;
					node_release(curr_node);
				}return 0;	
			}
			curr_node = curr_node->NEXT;			
		}
	}
	write(1,"no such node in list\n",sizeof("no such node in list\n"));
	return -1;
}
node_t* doublylinked_search_name(doublylinked_t* list, char name[]){
	node_t* curr_node;
	curr_node=list->HEAD;
	while(curr_node!=0x00){
		if(strcmp(curr_node->NAME, name) == 0){
			return curr_node;
		}
		curr_node = curr_node->NEXT;
	}
	write(1,"no such node in list\n",sizeof("no such node in list\n"));
	return NULL;
}
node_t* doublylinked_search_email(doublylinked_t* list, char EMAIL[]){
	node_t* curr_node;
	curr_node=list->HEAD;
	while(curr_node!=0x00){
		if(strcmp(curr_node->EMAIL, EMAIL) == 0){
			return curr_node;
		}
		curr_node = curr_node->NEXT;
	}
	write(1,"no such node in list\n",sizeof("no such node in list\n"));
	return NULL;
}
node_t* doublylinked_search_phone_number(doublylinked_t* list, char PHONE_NUMBER[]){
	node_t* curr_node;
	curr_node=list->HEAD;
	while(curr_node!=0x00){
		if(strcmp(curr_node->PHONE_NUMBER, PHONE_NUMBER) == 0){
			return curr_node;
		}
		curr_node = curr_node->NEXT;
	}
	write(1,"no such node in list\n",sizeof("no such node in list\n"));
	return NULL;
}
void doublylinked_print_list(doublylinked_t* list){
	node_t* curr_node = list->HEAD;
	while(curr_node!=0x00){
		node_print_node(curr_node);
		printf("#########################################################################\n");
		curr_node = curr_node->NEXT;	
	}
	
}
long unsigned int doublylinked_size_of_node(){
	return node_size_of_node();
}

node_t* doublylinked_buffer_to_node(char BUFFER[]){
	return node_buffer_to_node(BUFFER);
}

void doublylinked_print_node(node_t* node){
	node_print_node(node);
}

node_t* doublylinked_node_init(){
	return node_init();
}
node_t* doublylinked_create_node_with_data(char NAME[], char EMAIL[], char PHONE_NUMBER[]){
	return node_init_with_info(NAME, EMAIL, PHONE_NUMBER);
}
node_t* doublylinked_get_head_node(doublylinked_t* list){
	return list->HEAD;
}


