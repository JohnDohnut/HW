#ifndef __HW1_MANAGER_H__
#define __HW1_MANAGER_H__

#include <string.h>
#include "hw1_calculator.h"

typedef struct hw1_manager_s hw1_manager_t;
struct hw1_manager_s{
	char *name;
	hw1_calculator_t *calculator;/** function code in calculator.c, definition in calculator.h*/
	hw1_error_t error; /** enum error code in error.h*/
};

hw1_manager_t* hw1_manager_init(); /** manager functions*/
void hw1_manager_destroy( hw1_manager_t *manager);/** hw1_manager_t destroy function*/
char* hw1_manager_set_name( hw1_manager_t *manager, char *name);/**set manager->name function*/
void hw1_manager_process_data( hw1_manager_t *manager, int data);/**proc data function */

#endif

