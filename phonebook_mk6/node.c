
#include "node.h"

/**
*@breif initialize node, initially member NEXT and PREV is NULL
*@return node_t*
*/
node_t* node_init() {
	node_t* new_node = malloc(sizeof(node_t));
	memset(new_node,0x00,sizeof(node_t));
	return new_node;
}
node_t* node_init_with_info(char NAME[], char EMAIL[], char PHONE_NUMBER[]) {
	node_t* new_node = malloc(sizeof(node_t));
	node_set_name(new_node, NAME);
	node_set_email(new_node, EMAIL);
	node_set_phone_number(new_node, PHONE_NUMBER);
	node_set_next(new_node, 0x00);
	node_set_prev(new_node, 0x00);

	return new_node;
	
}

/**
*@brief free given param node_t*
*@param node_t*
*/
void node_release(node_t* node) {
	free(node);
}
/**
*@brief return NAME member of given param node_t*
*@param node_t*
*@return char[25]
*/
char* node_get_name(node_t* node) {
	if (node == NULL) {
		node->ERROR = PARAM_NULL;
		return NULL;
	}
	return node->NAME;
}
/**
*@brief return EMAIL member of given param node_t*
*@param node_t*
*@return char[30]
*/
char* node_get_email(node_t* node) {
	if (node == NULL) {
		node->ERROR = PARAM_NULL;
		return NULL;
	}
	return node->EMAIL;
}
/**
*@brief return PHONE_NUMBER member of given param node_t*
*@param node_t*
*@return char[15]
*/
char* node_get_phone_number(node_t* node) {
	if (node == NULL) { 
		node->ERROR = PARAM_NULL;
		return NULL;
	}
	return node->PHONE_NUMBER;
}
/**
*@brief set value of NAME member of given node_t*
*@param node_t*
*@param char[]
*/
int node_set_name(node_t* node, char name[]) {
	strncpy(node->NAME,name,sizeof(node->NAME));
}
/**
*@brief set value of EMAIL member of given node_t*
*@param node_t*
*@param char[]
*/
int node_set_email(node_t* node, char email[]) {
	strncpy(node->EMAIL, email, sizeof(node->EMAIL));
}
/**
*@brief set value of PHONE_NUMBER member of given node_t*
*@param node_t*
*@param char[]
*/
int node_set_phone_number(node_t* node, char phone_number[]) {
	strncpy(node->PHONE_NUMBER, phone_number, sizeof(node->PHONE_NUMBER));
}
/**
*@brief copy members of node_t* source to node_t* dest
*@param node_t* 
*@param node_t*
*/
void copy_node(node_t* SOURCE, node_t* DEST) {
	memcpy(DEST,SOURCE,sizeof(node_t));
}
/**
*@brief print given param node_t* node
*@param node_t*
*@return int
*/
int node_print_node(node_t* node){
	if(node ==NULL){
		printf("NULL\n");
		return PARAM_NULL;
	}	
	printf("name : %s\t",node_get_name(node));
	printf("phone_number : %s\t",node_get_phone_number(node));
	printf("email : %s\n",node_get_email(node));
	return 0;
}

long unsigned int node_size_of_node(){
	return sizeof(node_t);
}

node_t* node_get_next_node(node_t* node){
	return node->NEXT;
}
node_t* node_buffer_to_node(char* BUFFER){
	node_t* node = malloc(sizeof(node_t));
	memcpy(node,BUFFER,sizeof(node_t));
	return node;
}

