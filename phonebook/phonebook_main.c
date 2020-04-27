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
* For 4, open "DB.bin" with <O_WDRD|O_CREAT,0644> read and make list like (1,2,3), delete match node.
* For 5, open "DB.bin" with <O_WRONLY|O_APPEND>, make new column struct and write it on "DB,bin"
*/
int main(int argc, char* argv[]) {
	int FD;
	int COUNT=0;
	int READ_NUMBER;
	char TARGET_DATA[30];
	FILE* DB;
	column* BUFFER = column_init();
	column* HEAD = column_init();
	column* NEW_NODE;
	column* CURR_NODE = column_init();
	if (argc < 3){
		printf("Need more parameter\n");
	}
	memset(BUFFER,0x00,sizeof(column));
	if(atoi(argv[1]) == 1){
		printf("Email Search\n\n");
		strncpy(TARGET_DATA,argv[2],sizeof(TARGET_DATA));
		FD = open("DB.bin",O_RDONLY);
		while(read(FD,BUFFER,sizeof(column))!=0){
			if(COUNT == 0){
				copy_column(BUFFER,HEAD);
				CURR_NODE=HEAD;
				COUNT++;
			}
			else{	
				NEW_NODE = column_init();			
				copy_column(BUFFER,NEW_NODE);
				CURR_NODE->NEXT = NEW_NODE;
				NEW_NODE->PREV = CURR_NODE;
				CURR_NODE = NEW_NODE;
			}			
		}
		printf("Database loaded\n\n");
		CURR_NODE = HEAD;
		while(CURR_NODE != NULL){
			printf("%s -> ",CURR_NODE->COLUMN_NAME);
			CURR_NODE=CURR_NODE->NEXT;
		}
		printf("NULL\n");
		
		CURR_NODE = search_email(HEAD,TARGET_DATA);
		if(CURR_NODE ==NULL){
			printf("No Match Found\n");
			CURR_NODE=HEAD;
			while(CURR_NODE!=NULL){
				HEAD=CURR_NODE->NEXT;
				column_release(CURR_NODE);
				CURR_NODE=HEAD;	
			}
			column_release(HEAD);
			column_release(BUFFER);
			column_release(NEW_NODE);
			return 0;
		}
		else{
			printf("name : %s \nnumber : %s \n",CURR_NODE->COLUMN_NAME,CURR_NODE->COLUMN_PHONE_NUMBER);	

			while(CURR_NODE!=NULL){
				HEAD=CURR_NODE->NEXT;
                                column_release(CURR_NODE);
                                CURR_NODE=HEAD;
                        }
                        column_release(HEAD);
                        column_release(BUFFER);
                        column_release(NEW_NODE);
                        return 0;
		}
	}
	/*
	else if (argv[1] == 2){	
	}
	
	else if (argv[1] == 3){}

	else if (argv[1] == 4){}

	else if (argv[1] == 5){}

	else{}
*/




	
}
