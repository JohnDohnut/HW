#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "phonebook.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
*@brief read parameter and provide service
*@param char*
*@param char*
*@param char*
*@detail 
* 1:email search
* 2:name search
* 3:number search
* 4:delete by email
* 5:add column
*
* For (1,2,3), open "DB.bin" with <O_RDONLY> FLAG and read Data and make doubly-linked list with those data and store it in memory.
* Then, search with given parameter. 
* If match found, for (1,2,3), print name and number.
* For 4, load data and reopen DB.bin with <O_WRONLY|O_TRUNC> and write the modified list. 
* For 5, open "DB.bin" with <O_WRONLY|O_APPEND>, make new column struct and write it on "DB,bin".
*/
int main(int argc, char* argv[]) {
	int FD;
	int COUNT=0;
	int READ_NUMBER;
	char* TARGET_DATA = malloc(MAX_EMAIL_LENGTH+1);
	FILE* DB;
	int flag = -1;
	column* NEW_NODE;
	column* BUFFER = column_init();
	column* LIST=NULL;
	if (atoi(argv[1]) != 5 && argc < 3){
		printf("Need more parameter\n");
		return MAIN_PARAM_ERROR;
	}
	memset(BUFFER,'\0',sizeof(column));
	memset(TARGET_DATA,'\0',MAX_EMAIL_LENGTH+1);
	if(atoi(argv[1]) == 1){
		printf("Email Search\n\n");
		strncpy(TARGET_DATA,argv[2],strlen(argv[2]));
		printf("TD : %s\n\n",TARGET_DATA);
		FD = open("DB.bin",O_RDONLY);
		while(read(FD,BUFFER,sizeof(column))!=0){
			COUNT++;			
		NEW_NODE=column_init();
			copy_column(BUFFER,NEW_NODE);
			LIST =(column *) list_append_node(LIST,NEW_NODE);
		}
		printf("Database loaded\n\n");
		close(FD);
		LIST =(column*) list_find_head_node(LIST);
		while(LIST != NULL){
			printf("%s -> ",get_name(LIST));
			if(LIST->NEXT == NULL)
				break;
			LIST=LIST->NEXT;
		}
			printf("NULL\n");
		LIST =(column*)list_find_head_node(LIST);	
		LIST =(column*)list_search_email(LIST,TARGET_DATA);
		print_column(LIST);
		free(TARGET_DATA);
                column_release(BUFFER);
                column_release(NEW_NODE);
		release_list(LIST);	
                return 0;
		}
	
	else if (atoi(argv[1]) == 2){
		printf("Name Search\n");
		strncpy(TARGET_DATA,argv[2],strlen(argv[2]));
		FD = open("DB.bin",O_RDONLY);
		while(read(FD,BUFFER,sizeof(column))!=0){
			COUNT ++;
			NEW_NODE = column_init();
			copy_column(BUFFER,NEW_NODE);
			LIST = (column *)list_append_node(LIST,NEW_NODE);
		}
		printf("Database loaded\n\n");
		close(FD);
		LIST = (column*) list_find_head_node(LIST); // is this part necessary?? 
		while(LIST !=NULL){
			printf("%s ->",get_name(LIST));
			if(LIST->NEXT == NULL)
				break;
			LIST = LIST->NEXT;
		}
			printf("NULL\n");

		LIST = (column*)list_find_head_node(LIST);
		LIST = (column*)list_search_name(LIST,TARGET_DATA);
		print_column(LIST);
		free(TARGET_DATA);
		column_release(BUFFER);
		column_release(NEW_NODE);
		release_list(LIST);
		
		return 0;		
	}
	
	else if (atoi(argv[1]) == 3){
		printf("Phone Number Search\n\n");
		strncpy(TARGET_DATA,argv[2],strlen(argv[2]));
		FD = open("DB.bin",O_RDONLY);
		while(read(FD,BUFFER,sizeof(column))!=0){
			COUNT ++;
			NEW_NODE = column_init();
			copy_column(BUFFER,NEW_NODE);	
			LIST = list_append_node(LIST,NEW_NODE);
		}
		close(FD);
		printf("Database loaded\n\n");
		LIST =(column *)list_find_head_node(LIST);
		LIST = (column *)list_search_phone_number(LIST,TARGET_DATA);
		print_column(LIST);
		free(TARGET_DATA);
		column_release(BUFFER);
		column_release(NEW_NODE);
		release_list(LIST);
		
		return 0;
		
	}

	else if (atoi(argv[1]) == 4){
		printf("Delete by email\n\n");
		strncpy(TARGET_DATA,argv[2],strlen(argv[2]));
		printf("%d\n\n\n",sizeof(TARGET_DATA));
		FD = open ("DB.bin",O_RDONLY);
		while(read(FD,BUFFER,sizeof(column))!=0){
			COUNT ++;
			NEW_NODE = column_init();
			copy_column(BUFFER,NEW_NODE);
			LIST = list_append_node(LIST,NEW_NODE);
		}
		printf("Database loaded\n\n");
		close(FD);
		LIST = list_search_email(list_find_head_node(LIST),TARGET_DATA);
		if(LIST != NULL){
			LIST = list_delete_node(list_find_head_node(LIST),LIST);	
			FD = open("DB.bin",O_WRONLY|O_TRUNC);
			LIST = list_find_head_node(LIST);
			while(LIST != NULL){
				write(FD,LIST,sizeof(column));
				if(LIST->NEXT == NULL)			
					break;
				LIST = LIST->NEXT;
			}
			close(FD);
		}
		free(TARGET_DATA);
		column_release(BUFFER);
		column_release(NEW_NODE);
		release_list(list_find_head_node(LIST));
		
		
	
				
			
			
	}

	else if (atoi(argv[1]) == 5){
		int i;
		printf("Add Column\n\n");
		FD = open ("DB.bin",O_RDWR|O_APPEND);
		while(read(FD,BUFFER,sizeof(column))!=0){
			COUNT ++;
			NEW_NODE = column_init();
			copy_column(BUFFER,NEW_NODE);
			LIST = list_append_node(LIST,NEW_NODE);
		}
		printf("Database loaded\n\n");
		NEW_NODE = column_init();

			write(1,"Enter Name\n",13);

			char* USER_INPUT = malloc(MAX_EMAIL_LENGTH+1);
			read(0,USER_INPUT,25);
			USER_INPUT[strlen(USER_INPUT)-1] = '\0';
			strncpy(NEW_NODE->COLUMN_NAME, USER_INPUT,strlen(USER_INPUT));
			
			write(1,"Enter Phone Number\n",20);
			read(0,USER_INPUT,15);
			USER_INPUT[strlen(USER_INPUT)-1] = '\0';
			strncpy(NEW_NODE -> COLUMN_PHONE_NUMBER, USER_INPUT,strlen(USER_INPUT));
				
			write(1,"Enter EMAIL\n",13);
			read(0,USER_INPUT,30);
			USER_INPUT[strlen(USER_INPUT)-1] = '\0';
			strncpy(NEW_NODE -> COLUMN_EMAIL,USER_INPUT, strlen(USER_INPUT));
		
		write(FD,NEW_NODE,sizeof(column));
		close(FD);
		column_release(BUFFER);
		column_release(NEW_NODE);
		release_list(LIST);
		free(TARGET_DATA);		
		free(USER_INPUT);
		return 0;			

	}

	else{
		write(1,"wrong param\n",13);
		return MAIN_PARAM_ERROR;
	}

	
}
