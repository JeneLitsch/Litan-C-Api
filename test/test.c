#include "litan_c_api.h"
#include <stdio.h>
#include <stdlib.h>

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


struct S {
	int a;
	int b;
};

void free_s(void * ptr) {
	free(ptr);
}

void make(struct ltn_CApi * api) {
	struct ltn_CObject obj;
	struct S * s = (struct S*) malloc(sizeof(struct S));
	s->a = 42;
	s->b = 1337;
	obj.ptr = (void *)s;
	obj.deleter = free_s;
	api->return_object(obj, api->core);
}


void use(struct ltn_CApi * api) {
	struct ltn_CObject obj = api->param_object(0, api->core);
	printf("a: %d\n", ((struct S*)obj.ptr)->a);
	printf("b: %d\n", ((struct S*)obj.ptr)->b);
}