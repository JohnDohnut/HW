#pragma once
#include "error.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_NAME_LENGTH 25
#define MAX_EMAIL_LENGTH 30
#define MAX_PHONE_NUMBER_LENGTH 15
typedef struct phonebook_column_s {
	char COLUMN_NAME[25];					/** space for name*/
	char COLUMN_EMAIL[30];					/** space for email*/
	char COLUMN_PHONE_NUMBER[15];			/** space for phone number*/
	struct phonebook_column_s* NEXT;					/** pointer for next node of doubly linked list*/
	struct phonebook_column_s* PREV;					/** pointer for previous nude of double linked list*/
	enum error ERROR;
}phonebook_column_s;


phonebook_column_s* phonebook_column_init();												/** initialize phonebook_column_s*/
phonebook_column_s* phonebook_column_init_with_info(char name[], char email[], char phone_number[], phonebook_column_s* next, phonebook_column_s* prev);
char* phonebook_get_column_name(phonebook_column_s* column);								/** get name of phonebook_column_s*/
char* phonebook_get_column_email(phonebook_column_s* column);							/** get email of phonebook_column_s*/
char* phonebook_get_column_phone_number(phonebook_column_s* column);							/** get phone_number of phonebook_column_s*/
void phonebook_set_column_name(phonebook_column_s* column, char name[]);					/** set name of phonebook_column_s*/
void phonebook_set_column_email(phonebook_column_s* column, char email[]);					/** set email of phonebook_column_s*/
void phonebook_set_column_phone_number(phonebook_column_s* column, char phone_number[]);			/** set phone_number of phonebook_column_s*/
void phonebook_release_column(phonebook_column_s* column);
void phonebook_copy_column(phonebook_column_s* source, phonebook_column_s* dest);						/** copy from source column to dest coulmn */
int phonebook_print_column(phonebook_column_s* column);

int phonebook_set_column_next(phonebook_column_s* TARGET, phonebook_column_s* NEXT);/** set NEXT of given column(node of doubly linked list) to given parameter NEXT*/
int phonebook_set_column_prev(phonebook_column_s* TARGET, phonebook_column_s* PREV);/** set PREV of given column(node of doubly linked list) to given parameter PREV*/


