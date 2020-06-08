#pragma once
#include "phonebook.h"

int main(int argc, char* argv[]){
	phonebook_t phonebook[1];
	phonebook_init(phonebook,argc,argv);
	phonebook_open_db(phonebook);
	phonebook_read_db(phonebook);
	phonebook_hanadle_data(phonebook);
	phonebook_write_db(phonebook);
	phonebook_close_db(phonebook);
	phonebook_release(phonebook);
	return 0;

}
