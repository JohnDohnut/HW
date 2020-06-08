#pragma once
#include "data.h"
#include "file.h"
typedef struct phonebook_s phonebook_t;
struct phonebook_s{
	data_t* data;/** struct data which phonebook contains*/
	file_t* file;   /** data file structure of phonebook*/
	int option;  /** argv[1]*/
	char ARG_BUFFER[MAX_EMAIL_LENGTH]; /**argv[2]*/
	char NODE_BUFFER[200]; /**buffer for file read*/
	char NAME_BUFFER[MAX_NAME_LENGTH];/** name buffer for user input to append node*/
	char EMAIL_BUFFER[MAX_EMAIL_LENGTH];/** email buffer for user input to append node*/
	char PHONE_NUMBER_BUFFER[MAX_PHONE_NUMBER_LENGTH];/** phone number buffer for user input to append node*/
	long unsigned int node_size;			/**size of node for doubly linked list(can be considered one row of phonebook in real world)*/		
};
int phonebook_init(phonebook_t* phonebook,int argc, char *argv[]);
phonebook_t phonebook_destroy(phonebook_t* phonebook);
phonebook_t phonebook_handle_parameter(phonebook_t* phonebook);
