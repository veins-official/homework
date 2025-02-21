#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
#include "io_status.h"
#include "main_test.h"


static int init_array (double*, size_t, double, double);
static int print_array (const double*, size_t, size_t);


static int init_array (double* array, size_t array_size, double min_value, double max_value) {
	double random_value;
	size_t i;
	
	if (min_value >= max_value) {
		for (i = 0; i < array_size; i++)
			array[i] = min_value;
	}
	else {
		for (i = 0; i < array_size; i++) {
			random_value = rand();
			array[i] = min_value + (random_value / RAND_MAX) * (max_value - min_value);
		}
	}
	
	return SUCCESS;
}

static int print_array (const double* array, size_t array_size, size_t printed_count) {
	size_t i;
	if (printed_count > array_size) printed_count = array_size;
	for (i = 0; i < printed_count; i++) printf ("%lg\n", array[i]);
	return SUCCESS;
}


int test (double *array, size_t array_size, size_t printed_count, int show_time, double min_value, double max_value, int number, unary_function applied_function) {
	double t;
	
	init_array (array, array_size, min_value, max_value);
	
	printf ("======= [ Test №%2d ] =======\n", number);
	print_array (array, array_size, printed_count);
	printf ("----------------------------\n");

	t = clock ();
	apply_function (array, array_size, applied_function);
	t = (clock () - t) / CLOCKS_PER_SEC;
	
	print_array (array, array_size, printed_count);
	if (show_time == 1) {
		printf ("----------------------------\n");
		printf ("Elapsed = %.2f\n", t);
	}
	printf ("============================\n\n");

	return SUCCESS;
}

