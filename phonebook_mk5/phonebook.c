
#include <data.h>

typedef struct phonebook_s phonebook_t;
struct phonebook_s{
	data_t* data;
	file* file 
	int argc;
	char *argv[];
	char BUFFER[200];
	long unsigned int node_size

	
}
int phonebook_init(phonebook_t* phonebook,int argc, char *argv[]){
	phonebook->data = data_t_init();
	phonebook->file = file_t_init();
	phonebook->argc=argc;
	phonebook->argv=argv;
	node_size=node_size_of_node();
	if(phonebook->argc==3){
		char ch=0x00;
		int arg_len = 0;
		while(ch != '\0'){
			ch=argv[1][arg_len];
			phonebook->BUFFER[arg_len]=ch;
			arg_len++;
			if(arg_len == 201){
				return -1;			
			}
		}
	}
}
phonebook_t phonebook_open_file(phonebook_t* phonebook){
	file_open_db(phonebook->file,atoi(phonebook->argv[1]));
}
phonebook_t phonebook_read_file(phonebook_t* phonebook){
	while(file_read_db(phonebook->file, phonebook->BUFFER, phonebook->node_size)!=0){
		
	}
}
phonebook_t phonebook_destroy(phonebook_t* phonebook){
	data_t_destroy(phonebook->data);
	file_s_destroy(phonebook->file);
}
phonebook_t phonebook_handle_data(phonebook_t* phonebook){
	memset(phonebook->BUFFER,0x00,sizeof(phonebook->BUFFER);
	if(phonebook->argc<3 && atoi(phonebook->argv[1])){		
		write(1,"wrong param\n",sizeof("wrong param\n"));
		return -1;
	}
	

	if(atoi(phonebook->argv[1])==1){
		print_node(data_search_name(phonebook->data, phonebook->BUFFER));	
	
	}
	else if(atoi(phonebook->argv[1])==2){
		print_node(data_search_email(phonebook->data,phonebook->BUFFER));
	
	}	
	else if(atoi(phonebook->argv[1])==3){
		print_node(data_search_phone_number(phonebook->data,phonebook->BUFFER));
			
	}
	else if(atoi(phonebook->argv[1])==4){
		
		data_delete_node(phonebook->data, phonebook->BUFFER);
		data_print_data(phonebook->data);
		
	}
	else if(atoi(phonebook->argv[1])==5){
		

		
	}
	else{
		return -1;
	}

}
