#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "error.h"

#define MAX_NAME_LENGTH 25				/**size of node_s.NAME*/
#define MAX_EMAIL_LENGTH 30				/**size of node_s.EMAIL*/
#define MAX_PHONE_NUMBER_LENGTH 15			/**size of node_s.PHONE_NUMBER*/
typedef struct node_s node_t; 
struct node_s{
	char NAME[25];					/** space for name*/
	char EMAIL[30];					/** space for email*/
	char PHONE_NUMBER[15];				/** space for phone number*/
	node_t* NEXT;					/** pointer for next node of doubly linked list*/
	node_t* PREV;					/** pointer for previous nude of double linked list*/
	enum error ERROR;					/** error code */
};	

node_t* test_init();
node_t* test_init2();
node_t* node_init();												/** initialize node */
node_t* node_init_with_info(char name[], char email[], char phone_number[]);
void node_release(node_t* node);
char* node_get_name(node_t* node);								/** get name of node_t*/
char* node_get_email(node_t* node);							/** get email of node_t*/
char* node_get_phone_number(node_t* node);							/** get phone_number of node_t*/
int node_set_name(node_t* node, char name[]);					/** set name of node_t*/
int node_set_email(node_t* node, char email[]);					/** set email of node_t*/
int node_set_phone_number(node_t* node, char phone_number[]);			/** set phone_number of node_t*/
int node_set_next(node_t* node, node_t* new_next);
int node_set_prev(node_t* node, node_t* new_prev);
long unsigned int node_size_of_node();
void node_copy_node(node_t* source, node_t* dest);						/** copy from source node to dest coulmn */
int node_print_node(node_t* node);
long unsigned int node_size_of_node();
node_t* node_get_next_node(node_t* node);
node_t* node_buffer_to_node(char* BUFFER);



