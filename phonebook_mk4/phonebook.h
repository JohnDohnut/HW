
#include <data.h>

typedef struct phonebook_s phonebook_t;
struct phonebook_s{
	data_t* data;
	int argc;
	char *argv[];
}

phonebook_t phonebook_init(phonebook_t* phonebook,int argc, char *argv[]);
phonebook_t phonebook_destroy(phonebook_t* phonebook);
phonebook_t phonebook_parameter_handler(phonebook_t* phonebook);
