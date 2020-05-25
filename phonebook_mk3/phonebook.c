#include "phonebook.h"


/**
*@breif initialize column, initially member COLUMN_NEXT and COLUMN_PREV is NULL
*@return phonebook_column_s*
*/
phonebook_column_s* phonebook_set_column_init() {
	phonebook_column_s* NEW_COLUMN = malloc(sizeof(phonebook_column_s));
	phonebook_set_column_name(NEW_COLUMN,NULL);
	phonebook_set_column_email(NEW_COLUMN,NULL);
	phonebook_set_column_phone_number(NEW_COLUMN,NULL);
	phonebook_set_column_next(NEW_COLUMN, NULL);
	phonebook_set_column_prev(NEW_COLUMN, NULL);
	return NEW_COLUMN;
}
phonebook_column_s* phonebook_set_column_init_with_info(char NAME[], char EMAIL[], char PHONE_NUMBER[], phonebook_column_s* NEXT, phonebook_column_s* PREV) {
	phonebook_column_s* NEW_COLUMN = malloc(sizeof(phonebook_column_s));
	phonebook_set_column_name(NEW_COLUMN, NAME);
	phonebook_set_column_email(NEW_COLUMN, EMAIL);
	phonebook_set_column_phone_number(NEW_COLUMN, PHONE_NUMBER);
	phonebook_set_column_next(NEW_COLUMN, NEXT);
	phonebook_set_column_prev(NEW_COLUMN, PREV);

	return NEW_COLUMN;
	
}
/**
*@brief free given param phonebook_column_s*
*@param phonebook_column_s*
*/
void phonebook_release_column(phonebook_column_s* column) {
	free(column);
}
/**
*@brief return COLUMN_NAME member of given param phonebook_column_s*
*@param phonebook_column_s*
*@return char[25]
*/
char* phonebook_get_column_name(phonebook_column_s* column) {
	if (column == NULL) {
		column->ERROR = PARAM_NULL;
		return NULL;
	}
	return column->COLUMN_NAME;
}
/**
*@brief return COLUMN_EMAIL member of given param phonebook_column_s*
*@param phonebook_column_s*
*@return char[30]
*/
char* phonebook_get_column_email(phonebook_column_s* column) {
	if (column == NULL) {
		column->ERROR = PARAM_NULL;
		return NULL;
	}
	return column->COLUMN_EMAIL;
}
/**
*@brief return COLUMN_PHONE_NUMBER member of given param phonebook_column_s*
*@param phonebook_column_s*
*@return char[15]
*/
char* phonebook_get_column_phone_number(phonebook_column_s* column) {
	if (column == NULL) { 
		column->ERROR = PARAM_NULL;
		return NULL;
	}
	return column->COLUMN_PHONE_NUMBER;
}
/**
*@brief set value of COLUMN_NAME member of given phonebook_column_s*
*@param phonebook_column_s*
*@param char[]
*/
void phonebook_set_column_name(phonebook_column_s* column, char name[]) {
	strncpy(column->COLUMN_NAME,name,sizeof(column->COLUMN_NAME));
}
/**
*@brief set value of COLUMN_EMAIL member of given phonebook_column_s*
*@param phonebook_column_s*
*@param char[]
*/
void phonebook_set_column_email(phonebook_column_s* column, char email[]) {
	strncpy(column->COLUMN_EMAIL, email, sizeof(column->COLUMN_EMAIL));
}
/**
*@brief set value of COLUMN_PHONE_NUMBER member of given phonebook_column_s*
*@param phonebook_column_s*
*@param char[]
*/
void phonebook_set_column_phone_number(phonebook_column_s* column, char phone_number[]) {
	strncpy(column->COLUMN_PHONE_NUMBER, phone_number, sizeof(column->COLUMN_PHONE_NUMBER));
}
/**
*@brief set set NEXT of given column(node of doubly linked list) to given parameter NEXT
*@param coulmn*
*@param coulmn*
*@return int
*@detail If parameter is NULL, return PARAM_NULL. Else, 0
*/
int phonebook_set_column_next(phonebook_column_s* TARGET, phonebook_column_s* NEXT) {
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
int phonebook_set_column_prev(phonebook_column_s* TARGET,  phonebook_column_s* PREV) {
        if (TARGET == NULL) {
                return PARAM_NULL;
        }
        TARGET->PREV = PREV;
        return 0;
}
/**
*@brief copy members of phonebook_column_s* source to phonebook_column_s* dest
*@param phonebook_column_s* 
*@param phonebook_column_s*
*/
void phonebook_copy_column(phonebook_column_s* SOURCE, phonebook_column_s* DEST) {
	memcpy(DEST->COLUMN_NAME, SOURCE->COLUMN_NAME, strlen(SOURCE->COLUMN_NAME) + 1); /** copy name */
	memcpy(DEST->COLUMN_EMAIL, SOURCE->COLUMN_EMAIL, strlen(SOURCE->COLUMN_EMAIL) + 1); /** copy email */
	memcpy(DEST->COLUMN_PHONE_NUMBER, SOURCE->COLUMN_PHONE_NUMBER, strlen(SOURCE->COLUMN_PHONE_NUMBER) + 1); /** copy phone number */
	DEST->PREV = SOURCE->PREV;
	DEST->NEXT = SOURCE->NEXT;
	DEST->ERROR = SOURCE->ERROR;
}
/**
*@brief print given param phonebook_column_s* column
*@param phonebook_column_s*
*@return int
*/
int phonebook_print_column(phonebook_column_s* COLUMN){
	if(COLUMN ==NULL){
		printf("NULL\n");
		return PARAM_NULL;
	}	
	printf("name : %s\n",phonebook_get_column_name(COLUMN));
	printf("phone_number : %s\n",phonebook_get_column_phone_number(COLUMN));
	printf("email : %s\n",phonebook_get_column_email(COLUMN));
	return 0;
}



