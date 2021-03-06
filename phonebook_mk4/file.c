#include <file.h>

file_t* file_t_init(){
	file_t* file = malloc(sizeof(file_t));
	file->FD = -1;
	return file;
}
int file_db_open(file_t* file int option){/**open file with given main param as an option*/
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
int file_db_close(file_t* file){/**close given file with FD file->FD*/
	close(file->FD);
	return 0;
}	
int file_t_destroy(file_s* file){	/**release struct file_s*/
	free(file);
	return 0;
}


