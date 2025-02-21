#include <stddef.h>

#include "function_applier.h"


int apply_function (double* array, size_t array_size, unary_function applied_function) {
	size_t i;
	for (i = 0; i < array_size; i++) {
		array[i] = (*applied_function) (array[i]);
	}
	return 0;
}

