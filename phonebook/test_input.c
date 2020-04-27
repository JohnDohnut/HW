#include "phonebook.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int FD = open("DB.bin",O_WRONLY|O_CREAT|O_APPEND);
	column* a = malloc(sizeof(column));
	strncpy(a->COLUMN_NAME, "Brian Leatherman", sizeof(a->COLUMN_NAME));
	strncpy(a->COLUMN_EMAIL, "Brian@Leather.net",sizeof(a->COLUMN_EMAIL));
	strncpy(a->COLUMN_PHONE_NUMBER, "8888888888",sizeof(a->COLUMN_PHONE_NUMBER));
	write(FD,a,sizeof(column));
	
	strncpy(a->COLUMN_NAME, "Elizabeth Wong", sizeof(a->COLUMN_NAME));	
	strncpy(a->COLUMN_EMAIL, "Elizabeth@Wong.org",sizeof(a->COLUMN_EMAIL));
	strncpy(a->COLUMN_PHONE_NUMBER, "9999999999",sizeof(a->COLUMN_PHONE_NUMBER));
	write(FD,a,sizeof(column));
	
}

