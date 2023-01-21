#include "litan_c_api.h"
#include <stdio.h>

void powf_2(struct ltn_CApi * api) {
	double x = api->param_float(0, api->core);
	double result = x * x;
	api->return_float(result, api->core);
}



void powi_3(struct ltn_CApi * api) {
	double x = api->param_int(0, api->core);
	double result = x * x * x;
	api->return_int(result, api->core);
}



void hello_world(struct ltn_CApi * api) {
	api->return_string("Hello World", api->core);
}



void print(struct ltn_CApi * api) {
	const char * s = api->param_string(0, api->core);
	printf(s);
}