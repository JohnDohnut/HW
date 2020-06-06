
#include <data.h>

typedef struct phonebook_s phonebook_t;
struct phonebook_s{
	data_t* data;
	file* file 
	int argc;
	char *argv[];
	long unsigned int node_size
}

phonebook_t phonebook_init(phonebook_t* phonebook,int argc, char *argv[]);
phonebook_t phonebook_destroy(phonebook_t* phonebook);
phonebook_t phonebook_handle_parameter(phonebook_t* phonebook);
