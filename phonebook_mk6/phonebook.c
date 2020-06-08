#include "phonebook.h"

int phonebook_init(phonebook_t* phonebook,int argc, char *argv[]){
	memset(phonebook,0x00,sizeof(phonebook_t));
	phonebook->data = data_t_init();
	phonebook->file = file_t_init();
	phonebook->node_size=node_size_of_node();
	phonebook->option=atoi(argv[1]);
	if((argc<3 && atoi(argv[1]) >= 1 && atoi(argv[1])<=4) || argc>=4 || argc<2){
		write(1,"Need more Param");
	}
	if(phonebook->option >=1 && phonebook->option <=4){
		char ch=0x00;
		int arg_len = 0;
		while(1){
			ch=argv[2][arg_len];
			phonebook->ARG_BUFFER[arg_len]=ch;
			if(ch=='\0'){
				break;
			}
			else if(arg_len == 30){
				if(phonebook->ARG_BUFFER[arg_len-1]!='\0'){
					printf("second argument is too long, part of input can be lost\n");
					phonebook->ARG_BUFFER[arg_len-1]='\0';
				}
				break;			
			}
			arg_len++;
		}
	}
	
}
void phonebook_open_db(phonebook_t* phonebook){
	file_open_db(phonebook->file,phonebook->option);
}
void phonebook_close_db(phonebook_t* phonebook){
	file_close_db(phonebook->file);
}
int phonebook_read_db(phonebook_t* phonebook){

	while(file_read_db(file_get_fd(phonebook->file), phonebook->NODE_BUFFER, phonebook->node_size)>0){
		
		data_append_buffer_data(phonebook->data, data_buffer_to_node(phonebook->NODE_BUFFER));
	}
	return 0;
}
void phonebook_release(phonebook_t* phonebook){
	data_t_release(phonebook->data);
	file_s_release(phonebook->file);
	free(phonebook);
}
int phonebook_handle_data(phonebook_t* phonebook){
	memset(phonebook->NODE_BUFFER,0x00,sizeof(phonebook->NODE_BUFFER));
	
	if(phonebook->option==1){
		print_node(data_search_name(phonebook->data, phonebook->NODE_BUFFER));	
		
	}
	else if(phonebook->option==2){
		print_node(data_search_email(phonebook->data,phonebook->NODE_BUFFER));
	
	}	
	else if(phonebook->option==3){
		print_node(data_search_phone_number(phonebook->data,phonebook->NODE_BUFFER));
			
	}
	else if(phonebook->option==4){
		
		data_delete_node(phonebook->data, phonebook->NODE_BUFFER);
		data_print_data(phonebook->data);
		
	}
	else if(phonebook->option==5){
		write(1,"name?\n",sizeof("name?\n"));
		read(0,phonebook->NAME_BUFFER,MAX_NAME_LENGTH);
		write(1,"email?\n",sizeof("email?\n"));
		read(0,phonebook->EMAIL_BUFFER,MAX_EMAIL_LENGTH);
		WRITE(1,"phonenumber?\n",sizeof("phonenumber?\n"));
		read(0,phonebook->PHONE_NUMBER_BUFFER,MAX_PHONE_NUMBER_LENGTH);		
		data_append_node(phonebook->data, data_create_node_with_data(phonebook->NAME_BUFFER, phonebook->EMAIL_BUFFER, phonebook->PHONE_NUMBER_BUFFER)); 						
	
	}
	else{
		return -1;
	}

}

void phonebook_write_db(phonebook_t* phonebook){
	char WRITE_BUFFER[phonebook->node_size];
	node_t* curr_node = data_get_head_node(phonebook->data);
	while(curr_node != 0x00){
		memcpy(WRITE_BUFFER,curr_node,phonebook->node_size);
		file_write_data(phonebook->file, phonebook->node_size);
		curr_node = curr_node->NEXT;
	}
}

void phonebook_print_list(phonebook_t* phonebook){
	data_print_data(phonebook -> data);
	
}
