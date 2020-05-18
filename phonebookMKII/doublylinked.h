#include "phonebook.h"

int set_column_next(column* TARGET, column* NEXT);/** set NEXT of given column(node of doubly linked list) to given parameter NEXT*/
int set_column_prev(column* TARGET, column* PREV);/** set PREV of given column(node of doubly linked list) to given parameter PREV*/
column* list_find_head_node(column* LIST);/** find head node from given list*/
column* list_find_tail_node(column* LIST);/** find tail node from given list*/ 
column* list_append_node(column* LIST, column* NEW_NODE);/** append given NEW_NODE to given LIST*/
column* list_delete_node(column* LIST, column* TARGET_NODE);/** delete given TARGET_NODE from given LIST*/
column* list_search_email(column* HEAD, char EMAIL[]);/** find node with value of COLUMN_EMAIL member is same with given parameter EMAIL*/
column* list_search_phone_number(column* HEAD, char PHONE_NUMBER[]);/**find node that value of COLUMN_PHONE_NUMBER is same with given parameter PHONE_NUMBER*/
column* list_search_name(column* HEAD, char NAME[]);/**find node that value of its  COLUMN_NAME member is same with given parameter NAME */
int release_list(column* HEAD); /**release doubly linked list*/
void print_list(column* HEAD) ; /**print given doubly linked list*/

