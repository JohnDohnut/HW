#include "hw1_manager.h"
/** 
*	@brief : malloc and initialize hw1_manager_t manager and return pointer of it
*	@return : hw1_manager_t *manager
*/
hw1_manager_t* hw1_manager_init(){
	hw1_manager_t *manager = ( hw1_manager_t*)malloc( sizeof( hw1_manager_t));
	manager->name = NULL;
	manager->calculator = hw1_calculator_init();
	if( manager->calculator == NULL){
		return NULL;
	}
	return manager;
}
/**	
*	@breif : free given hw1_manager_t *manager 
*	@param : hw1_manager_t *manager
*/
void hw1_manager_destroy( hw1_manager_t *manager){
	if( manager){
		if( manager->calculator){
			hw1_calculator_destroy( manager->calculator);
		}
		free( manager);
	}
}
/** @breif : set name of manager 
*	@param : hw1_manager_t *manager 
*	@param : char * name
*	return : if success, manager->name. if fail, NULL
*/ 
char* hw1_manager_set_name( hw1_manager_t *manager, char *name){
	if( manager){
		memcpy( manager->name, name, strlen(name));
		return manager->name;
	}
	else{
		printf("(hw1_manager) { Fail to set name, manager is NULL }\n");
		return NULL;
	}
}
/** @brief : call hw1_calculator_processdata() function and pass given parameter as hw1_calculator_processdata()'s parameter
*	@param : hw1_manager_t *manager
*	@param : int data
*/
void hw1_manager_process_data( hw1_manager_t *manager, int data){
	int rv;
	rv = hw1_calculator_process_data( manager->calculator, data);
	if( rv < 0){
		printf("(hw1_manager) { rv = %d }\n", rv);
	}
}

