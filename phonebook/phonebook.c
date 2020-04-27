#include "phonebook.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

/**
*@breif initialize column, initially member COLUMN_NEXT and COLUMN_PREV is NULL
*@return column*
**/
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
void column_release(column* column) {
	free(column);
}

char* get_name(column* column) {
	if (column == NULL) {
		column->ERROR = PARAM_NULL;
		return NULL;
	}
	return column->COLUMN_NAME;
}
char* get_email(column* column) {
	if (column == NULL) {
		column->ERROR = PARAM_NULL;
		return NULL;
	}
	return column->COLUMN_EMAIL;
}
char* get_phone_number(column* column) {
	if (column == NULL) { 
		column->ERROR = PARAM_NULL;
		return NULL;
	}
	return column->COLUMN_PHONE_NUMBER;
}
void set_column_name(column* column, char name[]) {
	strncpy(column->COLUMN_NAME,name,sizeof(column->COLUMN_NAME));
}
void set_column_email(column* column, char email[]) {
	strncpy(column->COLUMN_EMAIL, email, sizeof(column->COLUMN_EMAIL));
}
void set_column_phone_number(column* column, char phone_number[]) {
	strncpy(column->COLUMN_PHONE_NUMBER, phone_number, sizeof(column->COLUMN_PHONE_NUMBER));
}
int set_column_next(column* target, column* next) {
	if (target == NULL || next == NULL) {
		return PARAM_NULL;
	}
	target->NEXT = next;
	return 0;
}
int set_column_prev(column* target, column* prev) {
	if (target == NULL || prev == NULL) {
		return PARAM_NULL;
	}
	target->PREV = prev;
	return 0;
}

void copy_column(column* source, column* dest) {
	memcpy(dest->COLUMN_NAME, source->COLUMN_NAME, strlen(source->COLUMN_NAME) + 1); /** copy name */
	memcpy(dest->COLUMN_EMAIL, source->COLUMN_EMAIL, strlen(source->COLUMN_EMAIL) + 1); /** copy email */
	memcpy(dest->COLUMN_PHONE_NUMBER, source->COLUMN_PHONE_NUMBER, strlen(source->COLUMN_PHONE_NUMBER) + 1); /** copy phone number */
	dest->PREV = source->PREV;
	dest->NEXT = source->NEXT;
	dest->ERROR = source->ERROR;
}
column* search_name(column* head, char name[]) {

	while (head != NULL) {
		/**
		* following statement 
		* memcmp(head->COLUMN_NAME, name, strnlen_s(name,MAX_NAME_LENGTH)) == 0 
		* didn't work
		**/
		if (head == NULL) {
			printf("parameter head node missing");
			return NULL;
		}

		if (strcmp(head->COLUMN_NAME,name)==0) {
			return head;
		}

		printf("this column not match ");
		head=head->NEXT; 
	}
	return head;
}

column* search_email(column* head, char email[]) {
	if (head == NULL) {
		printf("parameter head node missing");
		return NULL;
	}
	while (head != NULL) {
		if (strcmp(head->COLUMN_EMAIL, email) == 0) {
			return head;
		}
		head = head->NEXT;
	}

	return NULL;
}

column* search_phone_number(column* head, char phone_number[]) {
	if (head == NULL) {
		printf("parameter head node missing");
		return NULL;
	}
	while (head != NULL) {
		if ( strcmp(head->COLUMN_PHONE_NUMBER,phone_number)==0) {
			return head;
		}
		head=head->NEXT;
	}
	printf("match not found");
	return NULL;
}

