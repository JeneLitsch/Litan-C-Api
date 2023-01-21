#include "litan_c_api.h"

void powf_2(struct CApi * api) {
	double x = api->param_float(0, api->core);
	double result = x * x;
	api->return_float(result, api->core);
}



void powi_3(struct CApi * api) {
	double x = api->param_int(0, api->core);
	double result = x * x * x;
	api->return_int(result, api->core);
}