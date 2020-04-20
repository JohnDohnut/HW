#include "hw1_manager.h"
/**
*@breif : store data if given data is bigger than old data
*@param : char** argv
*return : if error, -1
**/
int main(int argc, char **argv){
	if( argc != 2){
		printf("\n(hw1_main) { Wrong Parameter Rule }\n\n");
		return -1;
	}

	int data = 0;
	hw1_manager_t *manager = hw1_manager_init(); /** declare and initialize by hw1_manager_init function*/
	if( manager == NULL){/** if fails*/
		printf("(hw1_main) { Fail to init manager }\n");
		return -1;
	}

	data = atoi( argv[1]);
	hw1_manager_process_data( manager, data);

	hw1_manager_destroy( manager);
}

