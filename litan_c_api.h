#ifndef LTN_C_API_H
#define LTN_C_API_H
#include <stdint.h>

struct CApi {
	void * core;

	int64_t (*param_int)(uint64_t index, void * core);
	uint8_t (*param_bool)(uint64_t index, void * core);
	double (*param_float)(uint64_t index, void * core);
	const char * (*param_string)(uint64_t index, void * core);

	void (*return_int)(int64_t value,  void * core);
	void (*return_bool)(uint8_t value, void * core);
	void (*return_float)(double value, void * core);
	void (*return_string)(const char * value, void * core);
};

#endif