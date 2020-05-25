#include "doublylinked.h"



/**
*@brief return head node of give parameter phonebook_column_s*
*@param coulmn*
*@return phonebook_column_s*
*@return NULL
*@detail if LIST is null, then return NULL. Else, return phonebook_column_s*. column is node of doublylinked list
*/        
phonebook_column_s* doublylinked_find_head_node(phonebook_column_s* LIST){
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
*@brief return tail node of give parameter phonebook_column_s*
*@param coulmn*
*@return phonebook_column_s*
*@return NULL
*@detail if LIST is null, then return NULL. Else, return phonebook_column_s*. column is node of doublylinked list
*/  
phonebook_column_s* doublylinked_find_tail_node(phonebook_column_s* LIST){
	if(LIST == NULL){
			printf("LIST is NULL\n");
	}
		while(LIST->NEXT != NULL){
			LIST=LIST->NEXT;
		}
	return LIST;
}
/**
*@brief append node of list phonebook_column_s* NEW_NODE to tail of given node phonebook_column_s* LIST.
*@param coulmn*
*@param phonebook_column_s*
*@return phonebook_column_s*
*@return NULL
*@detail 
* If LIST is null, then return NULL. 
* Flag remains -1 if there's error on all set_column_* functions.
* If there's no error, returns appended parameter NEW_NODE  
*/  
phonebook_column_s* doublylinked_list_append_node(phonebook_column_s* LIST, phonebook_column_s* NEW_NODE){
	phonebook_column_s* result = NULL;
	int flag = -1;
	if(LIST == NULL){
		flag = phonebook_set_column_prev(NEW_NODE,NULL);
			if(flag != 0){
				return NULL;
			}
		phonebook_set_column_next(NEW_NODE,NULL);
			if(flag != 0){
				return NULL;
			}
		result=NEW_NODE;
		return result;
	}
	
	LIST = doublylinked_find_tail_node(LIST);
	flag = phonebook_set_column_next(LIST,NEW_NODE);
		if(flag !=0){
			printf("set column next fail\n");
			return NULL;
		}
	flag = phonebook_set_column_prev(NEW_NODE,LIST);
		if(flag !=0){
			printf("set column prev fail\n");
			return NULL;
		}
	flag = phonebook_set_column_next(NEW_NODE,NULL);
		if(flag !=0){
			printf("set column next fail\n");
			return NULL;
		}
	return NEW_NODE;
}
/**
*@brief delete given parameter phonebook_column_s* TARGET_NODE from given doubly linked list phonebook_column_s* LIST. doubly linked list is given by NODE.
*@param phonebook_column_s*
*@param phonebook_column_s*
*@return phonebook_column_s*
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
phonebook_column_s* doublylinked_list_delete_node(phonebook_column_s* LIST, phonebook_column_s* TARGET_NODE){
	phonebook_column_s* RESULT_LIST;
	int flag=-1;
	if(LIST == NULL || TARGET_NODE == NULL){
			return NULL;
	}


	phonebook_column_s* HEAD = doublylinked_find_head_node(LIST);
	
	LIST = HEAD;
	RESULT_LIST = HEAD;
	while(LIST != NULL){

		if(LIST == TARGET_NODE){
			printf("del match found.. : %s\n\n",LIST->COLUMN_NAME);
			if(LIST->PREV == NULL){
				RESULT_LIST = LIST->NEXT;
				flag = phonebook_set_column_prev(RESULT_LIST,NULL);
				phonebook_release_column(LIST);
				if(flag != 0){
					return NULL;
				}

				return RESULT_LIST;
			}
			else if(LIST->NEXT == NULL){
				phonebook_set_column_next(LIST->PREV,NULL);
				RESULT_LIST=doublylinked_find_head_node(LIST->PREV);
				phonebook_release_column(LIST);
				return RESULT_LIST;					
			}
			else{
				flag = phonebook_set_column_next(LIST->PREV,LIST->NEXT);
					if(flag!=0){			
						return NULL;
					}
				flag = phonebook_set_column_prev(LIST->NEXT,LIST->PREV);
					if(flag!=0){
						return NULL;
					}
				RESULT_LIST =doublylinked_find_head_node(LIST->NEXT);
				phonebook_release_column(LIST);
				return RESULT_LIST;
			}
		}
	LIST = LIST->NEXT;
	}
	write(1,"no node found to delete\n\n",25);
	return RESULT_LIST;
}
/**
*@brief Search node from given doubly linked list phonebook_column_s* LIST which member COLUMN_EMAIL matches the given parameter char* EMAIL.
*@param phonebook_column_s*
*@param char*
*@return phonebook_column_s*
*@return NULL
*@detail
*return phonebook_column_s* LIST if match found. 
*else if error occurs, return NULL.
*else if there's no matched node, return NULL.
*/
phonebook_column_s* doublylinked_list_search_email(phonebook_column_s* LIST, char* EMAIL){
	if(LIST == NULL||EMAIL == NULL){
		return NULL;
	}
	LIST=doublylinked_find_head_node(LIST);
	while(LIST != NULL){
		if(strcmp(LIST->COLUMN_EMAIL,EMAIL)==0){
			return LIST;
		}
		LIST=LIST->NEXT;
	}
	return NULL;
	

}
/**
*@brief Search node from given doubly linked list phonebook_column_s* LIST which member COLUMN_PHONE_NUMBER matches the given parameter char* EMAIL.
*@param phonebook_column_s*
*@param char*
*@return phonebook_column_s*
*@return NULL
*@detail
*return phonebook_column_s* LIST if match found. 
*else if error occurs, return NULL.
*else if there's no matched node, return NULL.
*/
phonebook_column_s* doublylinked_list_search_phone_number(phonebook_column_s* LIST, char* PHONE_NUMBER){
	if(LIST == NULL || PHONE_NUMBER == NULL){
		return NULL;
	}
	LIST = doublylinked_find_head_node(LIST);
	while(LIST !=NULL){
		if(strcmp(LIST->COLUMN_PHONE_NUMBER,PHONE_NUMBER)==0){
			return LIST;
			}	
		
		LIST=LIST->NEXT;
	}
	return NULL;
}


/**
*@brief Search node from given doubly linked list phonebook_column_s* LIST which member COLUMN_NAME matches the given parameter char* EMAIL.
*@param phonebook_column_s*
*@param char*
*@return phonebook_column_s*
*@return NULL
*@detail
*return phonebook_column_s* LIST if match found. 
*else if error occurs, return NULL.
*else if there's no matched node, return NULL.
*/

phonebook_column_s* doublylinked_list_search_name(phonebook_column_s* LIST, char* NAME){
	if(LIST == NULL || NAME == NULL){
		printf("LIST/NAME NULL\n");
		return NULL;
	}
	LIST = doublylinked_find_head_node(LIST);	
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
*@param phonebook_column_s*
*@return int
*@return NULL
*@detail
*search head node and call phonebook_release_column for every nodes.
*return 0 if success.
*return NULL if parameter is NULL.
*/

int doublylinked_release_list(phonebook_column_s* LIST){
	if(LIST==NULL){
		return PARAM_NULL;
	}
	LIST = doublylinked_find_head_node(LIST);
	phonebook_column_s* TEMP;
	while(LIST!=NULL){
		TEMP = LIST->NEXT;
		phonebook_release_column(LIST);
		LIST=TEMP;
	}

	return 0;
}
/**
*@brief print list
*@param phonebook_column_s*
*/
void doublylinked_print_list(phonebook_column_s* LIST){
	LIST = doublylinked_find_head_node(LIST);
	while(LIST != NULL){
                        printf("%s -> ",get_name(LIST));
                        if(LIST->NEXT == NULL)
                                break;
                        LIST=LIST->NEXT;
                }
                        printf("NULL\n");


}
