#include "file.h"

file_t* file_t_init(){
	file_t* file = malloc(sizeof(file_t));
	file->FD = -1;
	return file;
}
int file_open_db(file_t* file, int option){/**open file with given main param as an option*/
	if(option == 1){
		file->FD = open("DB.bin",O_RDONLY);	
		return 1;
	}
	else if(option==2){
		file->FD = open("DB.bin",O_RDONLY);
		return 2;
	}
	else if(option==3){
		file->FD = open("DB.bin",O_RDONLY);
		return 3;
	}
	else if (option == 4){
		file->FD = open("DB.bin",O_RDWR|O_TRUNC);
		return 4;
	}
	else if (option == 5){
		file->FD = open("DB.bin",O_RDWR|O_APPEND);
		return 5;
	}
	else{
		return -1;
	}
}
int file_read_db(file_t* file,char BUFFER[],long unsigned int node_size){
	return read(file->FD, BUFFER, node_size);
	
}
int file_write_db(file_t* file, char BUFFER[],long unsigned int buffer_size){
	return write(file->FD,BUFFER,buffer_size);
}
int file_close_db(file_t* file){/**close given file with FD file->FD*/
	close(file->FD);
	return 0;
}	
int file_t_release(file_t* file){	/**release struct file_t*/
	free(file);
	return 0;
}

int file_get_FD(file_t* file){
	return file->FD;
}
