#ifndef LTN_C_API_H
#define LTN_C_API_H
#include <stdint.h>

struct ltn_CObject {
	void * ptr;
	void(*deleter)(void *);
};

struct ltn_CApi {
	void * core;

	int64_t (*param_int)(uint64_t index, void * core);
	uint8_t (*param_bool)(uint64_t index, void * core);
	double (*param_float)(uint64_t index, void * core);
	const char * (*param_string)(uint64_t index, void * core);
	struct ltn_CObject (*param_object) (uint64_t index, void * core);

	void (*return_int) (int64_t value,  void * core);
	void (*return_bool) (uint8_t value, void * core);
	void (*return_float) (double value, void * core);
	void (*return_string) (const char * value, void * core);
	void (*return_object) (struct ltn_CObject value, void * core);
};

#endif