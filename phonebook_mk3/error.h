#pragma once
typedef enum error_error_t {
	DEFAULT = 0,
	FUNCTION_PARAM_ERROR = -1,
	FILE_NOT_OPENED = -2,
	FILE_READ_ERROR = -3,
	FILE_WRITE_ERROR = -4,
	MAIN_PARAM_ERROR = -5,
	WRITE_UNAVAILABLE = -6,
	READ_UNAVAILABLE = -7
}error_t;
