
#include "doublylinked.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
*@brief set set NEXT of given column(node of doubly linked list) to given parameter NEXT
*@param coulmn*
*@param coulmn*
*@return int
*@detail If parameter is NULL, return PARAM_NULL. Else, 0
*/
int set_column_next(column* TARGET, column* NEXT) {
        if (TARGET == NULL) {
                return PARAM_NULL;
        }
        TARGET->NEXT = NEXT;
        return 0;
}
/**
*@brief set set PREV of given column(node of doubly linked list) to given parameter PREV
*@param coulmn*
*@param coulmn*
*@return int
*@detail If parameter is NULL, return PARAM_NULL. Else, 0
*/                            
int set_column_prev(column* TARGET,  column* PREV) {
        if (TARGET == NULL) {
                return PARAM_NULL;
        }
        TARGET->PREV = PREV;
        return 0;
}
/**
*@brief return head node of give parameter column*
*@param coulmn*
*@return column*
*@return NULL
*@detail if LIST is null, then return NULL. Else, return column*. column is node of doublylinked list
*/        
column* list_find_head_node(column* LIST){
	if(LIST == NULL){
		printf("LIST is NULL\n");
		return NULL;
	}
	while(LIST->PREV != NULL){
		LIST=LIST->PREV;
	}
	return LIST; 
}
/**
*@brief return tail node of give parameter column*
*@param coulmn*
*@return column*
*@return NULL
*@detail if LIST is null, then return NULL. Else, return column*. column is node of doublylinked list
*/  
column* list_find_tail_node(column* LIST){
	if(LIST == NULL){
			printf("LIST is NULL\n");
	}
		while(LIST->NEXT != NULL){
			LIST=LIST->NEXT;
		}
	return LIST;
}
/**
*@brief append node of list column* NEW_NODE to tail of given node column* LIST.
*@param coulmn*
*@param column*
*@return column*
*@return NULL
*@detail 
* If LIST is null, then return NULL. 
* Flag remains -1 if there's error on all set_column_* functions.
* If there's no error, returns appended parameter NEW_NODE  
*/  
column* list_append_node(column* LIST, column* NEW_NODE){
	column* result;
	int flag = -1;
	if(LIST == NULL){
		flag = set_column_prev(NEW_NODE,NULL);
			if(flag != 0){
				return NULL;
			}
		set_column_next(NEW_NODE,NULL);
			if(flag != 0){
				return NULL;
			}
		result=NEW_NODE;
		return result;
	}
	
	LIST = list_find_tail_node(LIST);
	flag = set_column_next(LIST,NEW_NODE);
		if(flag !=0){
			printf("set column next fail\n");
			return NULL;
		}
	flag = set_column_prev(NEW_NODE,LIST);
		if(flag !=0){
			printf("set column prev fail\n");
			return NULL;
		}
	flag = set_column_next(NEW_NODE,NULL);
		if(flag !=0){
			printf("set column next fail\n");
			return NULL;
		}
	return NEW_NODE;
}
/**
*@brief delete given parameter column* TARGET_NODE from given doubly linked list column* LIST. doubly linked list is given by NODE.
*@param column*
*@param column*
*@return column*
*@return NULL
*@detail
*If an error occurs in function, returns NULL.
*Process varies by if given TARGET_NODE is head of list or tail of list or else.
*Start from head node of given list LIST.
*If match node is found proceed the sequences below. 
*If given TARGET_NODE is head, detach the given node. And make next node as head node of the list. Which will be considered as head node of RESULT_LIST. 
*Then release given TARGET_NODE. 
*If given TARGET_NODE is tail, detach the given node. And make prev node as tail node of the list. Which will be considered as tail node of RESULT_LIST.
*Else, detach TARGET_NODE by changing NEXT of TARGET_NODE->PREV and PREV of TARGET_NODE -> NEXT.
*Return RESULT_LIST
*/
column* list_delete_node(column* LIST, column* TARGET_NODE){
	column* RESULT_LIST;
	int flag=-1;
	if(LIST == NULL || TARGET_NODE == NULL){
			return NULL;
	}


	column* HEAD = list_find_head_node(LIST);
	
	LIST = HEAD;
	RESULT_LIST = HEAD;
	while(LIST != NULL){

		if(LIST == TARGET_NODE){
			printf("del match found.. : %s\n\n",LIST->COLUMN_NAME);
			if(LIST->PREV == NULL){
				RESULT_LIST = LIST->NEXT;
				flag = set_column_prev(RESULT_LIST,NULL);
				column_release(LIST);
				if(flag != 0){
					return NULL;
				}

				return RESULT_LIST;
			}
			else if(LIST->NEXT == NULL){
				set_column_next(LIST->PREV,NULL);
				RESULT_LIST=list_find_head_node(LIST->PREV);
				column_release(LIST);
				return RESULT_LIST;					
			}
			else{
				flag = set_column_next(LIST->PREV,LIST->NEXT);
					if(flag!=0){			
						return NULL;
					}
				flag = set_column_prev(LIST->NEXT,LIST->PREV);
					if(flag!=0){
						return NULL;
					}
				RESULT_LIST =list_find_head_node(LIST->NEXT);
				column_release(LIST);
				return RESULT_LIST;
			}
		}
	LIST = LIST->NEXT;
	}
	write(1,"no node found to delete\n\n",25);
	return RESULT_LIST;
}
/**
*@brief Search node from given doubly linked list column* LIST which member COLUMN_EMAIL matches the given parameter char* EMAIL.
*@param column*
*@param char*
*@return column*
*@return NULL
*@detail
*return column* LIST if match found. 
*else if error occurs, return NULL.
*else if there's no matched node, return NULL.
*/
column* list_search_email(column* LIST, char* EMAIL){
	if(LIST == NULL||EMAIL == NULL){
		return NULL;
	}
	LIST=list_find_head_node(LIST);
	while(LIST != NULL){
		if(strcmp(LIST->COLUMN_EMAIL,EMAIL)==0){
			return LIST;
		}
		LIST=LIST->NEXT;
	}
	return NULL;
	

}
/**
*@brief Search node from given doubly linked list column* LIST which member COLUMN_PHONE_NUMBER matches the given parameter char* EMAIL.
*@param column*
*@param char*
*@return column*
*@return NULL
*@detail
*return column* LIST if match found. 
*else if error occurs, return NULL.
*else if there's no matched node, return NULL.
*/
column* list_search_phone_number(column* LIST, char* PHONE_NUMBER){
	if(LIST == NULL || PHONE_NUMBER == NULL){
		return NULL;
	}
	LIST = list_find_head_node(LIST);
	while(LIST !=NULL){
		if(strcmp(LIST->COLUMN_PHONE_NUMBER,PHONE_NUMBER)==0){
			return LIST;
			}	
		
		LIST=LIST->NEXT;
	}
	return NULL;
}


/**
*@brief Search node from given doubly linked list column* LIST which member COLUMN_NAME matches the given parameter char* EMAIL.
*@param column*
*@param char*
*@return column*
*@return NULL
*@detail
*return column* LIST if match found. 
*else if error occurs, return NULL.
*else if there's no matched node, return NULL.
*/

column* list_search_name(column* LIST, char* NAME){
	if(LIST == NULL || NAME == NULL){
		printf("LIST/NAME NULL\n");
		return NULL;
	}
	LIST = list_find_head_node(LIST);	
	while(LIST != NULL){
		if(strcmp(LIST->COLUMN_NAME,NAME)==0){
			return LIST;
		}
		LIST = LIST->NEXT;	
	}
	printf("no match name \n");
	return NULL;

}
/**
*@brief release given list by releasing all nodes starting from head node.
*@param column*
*@return int
*@return NULL
*@detail
*search head node and call column_release for every nodes.
*return 0 if success.
*return NULL if parameter is NULL.
*/

int release_list(column* LIST){
	if(LIST==NULL){
		return PARAM_NULL;
	}
	LIST = list_find_head_node(LIST);
	column* TEMP;
	while(LIST!=NULL){
		TEMP = LIST->NEXT;
		column_release(LIST);
		LIST=TEMP;
	}

	return 0;
}
/**
*@brief print list
*@param column*
*/
void print_list(column* LIST){
	LIST = list_find_head_node(LIST);
	while(LIST != NULL){
                        printf("%s -> ",get_name(LIST));
                        if(LIST->NEXT == NULL)
                                break;
                        LIST=LIST->NEXT;
                }
                        printf("NULL\n");


}
