#pragma once
#include "error.h"

#define MAX_NAME_LENGTH 24
#define MAX_EMAIL_LENGTH 29
#define MAX_PHONE_NUMBER_LENGTH 14
typedef struct _column {
	char COLUMN_NAME[25];					/** space for name*/
	char COLUMN_EMAIL[30];					/** space for email*/
	char COLUMN_PHONE_NUMBER[15];			/** space for phone number*/
	struct _column* NEXT;					/** pointer for next node of doubly linked list*/
	struct _column* PREV;					/** pointer for previous nude of double linked list*/
	enum error ERROR;
}column;

column* test_init();
column* test_init2();
column* column_init();												/** initialize column */
column* column_init_with_info(char name[], char email[], char phone_number[], column* next, column* prev);
char* get_name(column* column);								/** get name of column*/
char* get_email(column* column);							/** get email of column*/
char* get_phone_number(column* column);							/** get phone_number of column*/
void set_column_name(column* column, char name[]);					/** set name of column*/
void set_column_email(column* column, char email[]);					/** set email of column*/
void set_column_phone_number(column* column, char phone_number[]);			/** set phone_number of column*/
void copy_column(column* source, column* dest);						/** copy from source column to dest coulmn */
column* search_name(column* head, char name[]);						/** search match column with name*/
column* search_email(column* head, char email[]);					/** search match column with email*/
column* search_phone_number(column* head, char phone_number[]);				/** search match column with phone number*/
int print_column(column* column);




