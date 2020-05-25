#include "phonebook.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>

phonebook_column_s* doublylinked_find_head_node(phonebook_column_s* LIST);/** find head node from given list*/
phonebook_column_s* doublylinked_find_tail_node(phonebook_column_s* LIST);/** find tail node from given list*/ 
phonebook_column_s* doublylinked_list_append_node(phonebook_column_s* LIST, phonebook_column_s* NEW_NODE);/** append given NEW_NODE to given LIST*/
phonebook_column_s* doublylinked_list_delete_node(phonebook_column_s* LIST, phonebook_column_s* TARGET_NODE);/** delete given TARGET_NODE from given LIST*/
phonebook_column_s* doublylinked_list_search_email(phonebook_column_s* HEAD, char EMAIL[]);/** find node with value of COLUMN_EMAIL member is same with given parameter EMAIL*/
phonebook_column_s* doublylinked_list_search_phone_number(phonebook_column_s* HEAD, char PHONE_NUMBER[]);/**find node that value of COLUMN_PHONE_NUMBER is same with given parameter
PHONE_NUMBER*/
phonebook_column_s* doublylinked_list_search_name(phonebook_column_s* HEAD, char NAME[]);/**find node that value of its  COLUMN_NAME member is same with given parameter NAME */
int doublylinked_release_list(phonebook_column_s* HEAD); /**release doubly linked list*/
void doublylinked_print_list(phonebook_column_s* HEAD) ; /**print given doubly linked list*/

