#include "hw1_calculator.h"

/**	
*	@breif : malloc and initialize hw1_calculator_t and return it,
*	@return : hw1_calculator_t *calculator
*/
hw1_calculator_t* hw1_calculator_init(){ 
	hw1_calculator_t *calculator = ( hw1_calculator_t*)malloc( sizeof( hw1_calculator_t*));
	calculator->data = 0;
	calculator->count = 0;
	return calculator;
}

/** 
*	@breif : free calculator
*	@param : hw1_calculator_t *calculator
*	@return : void
*/
void hw1_calculator_destroy( hw1_calculator_t *calculator){ 
	if( calculator){
		free( calculator);
	}
}

/**	
*	@breif : get count value from given hw1_calculator_t parameter
*	@param : hw1_calculator_t *calculator
*	@return : if sucess, return  int count. if fail, return  int error code
*/
int hw1_calculator_get_count( hw1_calculator_t *calculator){ 
	if( calculator){
		return calculator->count;
	}
	else{/** if object is null*/
		printf("(hw1_calculator) { Fail to get count, calculator is NULL }\n");
		calculator->error = OBJ_NULL; /** set error code*/
		return calculator->error;
	}
}
/** 
*	@breif : add 1 to member count of given parameter hw1_calculator_t
*	@param : hw1_calculator_t *calculator
*	@return : if success, added count. if error, error code
*/
int hw1_calculator_plus_count( hw1_calculator_t *calculator){
	if( calculator){
		if( hw1_calculator_get_count( calculator) > CAL_MAX_NUM){
			printf("(hw1_calculator) { Fail to plus count, count is MAX value }\n");
			calculator->error = COUNT_FULL;
			return calculator->error;
		}
		else{
			return ++( calculator->count);
		}
	}
	else{
		printf("(hw1_calculator) { Fail to plus count, calculator is NULL }\n");
		calculator->error = OBJ_NULL;
		return calculator->error;
	}
}
/** 
*	@breif : subtract 1 to member count of given parameter hw1_calculator_t
*	@param : hw1_calculator_t *calculator
*	@return : if success, subtracted count. if error, error code
*/
int hw1_calculator_minus_count( hw1_calculator_t *calculator){
	if( calculator){/** if we have pointer */
		if( hw1_calculator_get_count( calculator) == 0){ /** if count is 0*/
			printf("(hw1_calculator) { Fail to minus count, calculator is 0 }\n");
			calculator->error = COUNT_ZERO;
			return calculator->error;
		}
		else{ /** if there's no error*/
			return --( calculator->count);
		}
	}
	else{/** if calculator is NULL ( no pointer) */
		printf("(hw1_calculator) { Fail to minus count, calculator is NULL }\n");
		calculator->error = OBJ_NULL;
		return calculator->error;
	}
}
/**	
*	@brief : return member data from given parameter hw1_calculator_t
*	@param : hw1_calculator_t *calculator
*	@return : if sucess, data. if fails, error code 
*/
int hw1_calculator_get_data( hw1_calculator_t *calculator){
	if( calculator){ /** if we have not null address */
		return calculator->data; /** return data*/
	}
	else{/** if fail to get address of calculator (NULL)*/
		printf("(hw1_calculator) { Fail to get data, calculator is NULL }\n");
		calculator->error = OBJ_NULL;
		return calculator->error;
	}
}
/**	
*	@breif : save data and return it if data is bigger than old one and count value >= 0
*	@param : hw1_calculator_t *calculator
*	@param : int data
*	@return : if success, int data. if fails, error code.
*/
int hw1_calculator_process_data( hw1_calculator_t *calculator, int data){
	if( calculator){
		int rv, temp_data;

		temp_data = hw1_calculator_get_data( calculator);
		if( temp_data < 0){
			printf("(hw1_calculator) { rv = %d }\n", rv);
			return calculator->error;
		}
		else if( temp_data > data){
			printf("(hw1_calculator) { Fail to process data }\n");
			printf("(hw1_calculator) { Received data is less than saved data }\n");
			calculator->error = DATA_LESS;
			return calculator->error;
		}

		rv = hw1_calculator_plus_count( calculator);
		if( rv < 0){
			printf("(hw1_calculator) { rv = %d }\n", rv);
			return calculator->error;
		}
		
		(calculator->data) += data;
		printf("\n(hw1_calculator) [ Success to process data, saved data : %d ]\n\n", calculator->data);
		return calculator->data;
	}
	else{
		printf("(hw1_calculator) { Fail to process data, calculator is NULL }\n");
		calculator->error = OBJ_NULL;
		return calculator->error;
	}

}

