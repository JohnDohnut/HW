
#include "doublylinked.h"


doublylinked_t* doublylinked_list_init(){
	doublylinked_t* list = malloc(sizeof(doublylinked_t));
	memset(list,0x00,sizeof(doublylinked_t));
}
void doublylinked_destroy(doublylinked_t* list){
	node_t* curr_node;
	node_t* temp;
	curr_node = list->HEAD;
	while(curr_node != NULL){
		temp=curr_node->NEXT;
		node_destroy(curr_node);
		curr_node=temp;
	}
	free(list);
}
int doublylinked_append_node(doublylinked_t* list, node_t* node){
	if(list->HEAD == NULL){
		list->HEAD = node;
		list->TAIL = node;
	}
	if(list->TAIL == NULL){
		write(1,"broken list",sizeof("broken list\n")); 
		return -1;
	}
	list->TAIL->NEXT = node;
	node->PREV = list->TAIL;
	node->NEXT = NULL;
	list->TAIL = node;
	return 0;
}
int doublylinked_delete_node(doublylinked_t* list, node_t* node){
	node_t* = curr_node;
	curr_node=list->HEAD;
	while(curr_node!=NULL){
		if(curr_node == node){
			curr_node->NEXT->PREV = curr_node->PREV;
			curr_node->PREV->NEXT = curr_node->NEXT;
			node_destroy(node);
			return 0;	
		}
		curr_node = curr_node->NEXT;			
	}
	write(1,"no such node in list\n",sizeof("no such node in list\n"));
	return -1;
}
node_t* doublylinked_search_name(doublylinked_t* list,char* name){
	node_t* curr_node;
	curr_node=list->HEAD;
	while(curr_node!=NULL){
		if(strcmp(curr_node->NAME, name) == 0){
			return curr_node;
		}
		curr_node = curr_node->NEXT;
	}
	write(1,"no such node in list\n",sizeof("no such node in list\n"));
	return NULL;
}
node_t* doublylinked_search_email(doublylinked_t* list, char* EMAIL){
	node_t* curr_node;
	curr_node=list->HEAD;
	while(curr_node!=NULL){
		if(strcmp(curr_node->EMAIL, EMAIL) == 0){
			return curr_node;
		}
		curr_node = curr_node->NEXT;
	}
	write(1,"no such node in list\n",sizeof("no such node in list\n"));
	return NULL;
}
node_t* doublylinked_search_phone_number(doublylinked_t* list, char* PHONE_NUMBER){
	node_t* curr_node;
	curr_node=list->HEAD;
	while(curr_node!=NULL){
		if(strcmp(curr_node->PHONE_NUMBER, PHONE_NUMBER) == 0){
			return curr_node;
		}
		curr_node = curr_node->NEXT;
	}
	write(1,"no such node in list\n",sizeof("no such node in list\n"));
	return NULL;
}


