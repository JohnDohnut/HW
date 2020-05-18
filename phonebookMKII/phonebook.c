#include "phonebook.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

/**
*@breif initialize column, initially member COLUMN_NEXT and COLUMN_PREV is NULL
*@return column*
*/
column* column_init() {
	column* NEW_COLUMN = malloc(sizeof(column));
	set_column_next(NEW_COLUMN, NULL);
	set_column_prev(NEW_COLUMN, NULL);
	return NEW_COLUMN;
}
column* column_init_with_info(char NAME[], char EMAIL[], char PHONE_NUMBER[], column* NEXT, column* PREV) {
	column* NEW_COLUMN = malloc(sizeof(column));
	set_column_name(NEW_COLUMN, NAME);
	set_column_email(NEW_COLUMN, EMAIL);
	set_column_phone_number(NEW_COLUMN, PHONE_NUMBER);
	set_column_next(NEW_COLUMN, NEXT);
	set_column_prev(NEW_COLUMN, PREV);

	return NEW_COLUMN;
	
}
/**
*@brief free given param column*
*@param column*
*/
void column_release(column* column) {
	free(column);
}
/**
*@brief return COLUMN_NAME member of given param column*
*@param column*
*@return char[25]
*/
char* get_name(column* column) {
	if (column == NULL) {
		column->ERROR = PARAM_NULL;
		return NULL;
	}
	return column->COLUMN_NAME;
}
/**
*@brief return COLUMN_EMAIL member of given param column*
*@param column*
*@return char[30]
*/
char* get_email(column* column) {
	if (column == NULL) {
		column->ERROR = PARAM_NULL;
		return NULL;
	}
	return column->COLUMN_EMAIL;
}
/**
*@brief return COLUMN_PHONE_NUMBER member of given param column*
*@param column*
*@return char[15]
*/
char* get_phone_number(column* column) {
	if (column == NULL) { 
		column->ERROR = PARAM_NULL;
		return NULL;
	}
	return column->COLUMN_PHONE_NUMBER;
}
/**
*@brief set value of COLUMN_NAME member of given column*
*@param column*
*@param char[]
*/
void set_column_name(column* column, char name[]) {
	strncpy(column->COLUMN_NAME,name,sizeof(column->COLUMN_NAME));
}
/**
*@brief set value of COLUMN_EMAIL member of given column*
*@param column*
*@param char[]
*/
void set_column_email(column* column, char email[]) {
	strncpy(column->COLUMN_EMAIL, email, sizeof(column->COLUMN_EMAIL));
}
/**
*@brief set value of COLUMN_PHONE_NUMBER member of given column*
*@param column*
*@param char[]
*/
void set_column_phone_number(column* column, char phone_number[]) {
	strncpy(column->COLUMN_PHONE_NUMBER, phone_number, sizeof(column->COLUMN_PHONE_NUMBER));
}
/**
*@brief copy members of column* source to column* dest
*@param column* 
*@param column*
*/
void copy_column(column* SOURCE, column* DEST) {
	memcpy(DEST->COLUMN_NAME, SOURCE->COLUMN_NAME, strlen(SOURCE->COLUMN_NAME) + 1); /** copy name */
	memcpy(DEST->COLUMN_EMAIL, SOURCE->COLUMN_EMAIL, strlen(SOURCE->COLUMN_EMAIL) + 1); /** copy email */
	memcpy(DEST->COLUMN_PHONE_NUMBER, SOURCE->COLUMN_PHONE_NUMBER, strlen(SOURCE->COLUMN_PHONE_NUMBER) + 1); /** copy phone number */
	DEST->PREV = SOURCE->PREV;
	DEST->NEXT = SOURCE->NEXT;
	DEST->ERROR = SOURCE->ERROR;
}
/**
*@brief print given param column* column
*@param column*
*@return int
*/
int print_column(column* COLUMN){
	if(COLUMN ==NULL){
		printf("NULL\n");
		return PARAM_NULL;
	}	
	printf("name : %s\n",get_name(COLUMN));
	printf("phone_number : %s\n",get_phone_number(COLUMN));
	printf("email : %s\n",get_email(COLUMN));
	return 0;
}



