#ifndef __HW1_CALCULATOR_H__
#define __HW1_CALCULATOR_H__
 
#define CAL_MAX_NUM 100

#include <stdlib.h>
#include "hw1_error.h"

typedef struct hw1_calculator_s hw1_calculator_t;
struct hw1_calculator_s{
	int data;
	int count;
	hw1_error_t error;
};

hw1_calculator_t* hw1_calculator_init();
void hw1_calculator_destroy( hw1_calculator_t *calculator); /** calculator function,free hw1_caculator_t* calculator */
int hw1_calculator_get_count( hw1_calculator_t *calculator);/** calculator function,get calculator->count from hw1_caculator_t* calculator*/
int hw1_calculator_plus_count( hw1_calculator_t *calculator);/**calculator function,et count and  add 1 and store it */
int hw1_calculator_minus_count( hw1_calculator_t *calculator);/**calculator function,get count and subtract 1 and store it */
int hw1_calculator_get_data( hw1_calculator_t *calculator);/**calculator function, get data from hw1_caculator_t* calculator */
int hw1_calculator_process_data( hw1_calculator_t *calculator, int data); /**calculator function, process data */

#endif

