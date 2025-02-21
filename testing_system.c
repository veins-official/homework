#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "unit_tests.h"
#include "io_status.h"
#include "main_test.h"
#include "config.h"


int main (int argc, char* argv[]) {
	size_t printed_count = PRINTED;
	size_t array_size = ARRAY_SIZE;
	unsigned char flags = 0;
	unsigned int seed = SEED;
	double min_value = MIN_VALUE, max_value = MAX_VALUE;
	int show_time;
	double *array;
	int i;
	
	if (argc < 2)
		printf ("Usage: %s -h\n\n", argv[0]);
	
	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
			printf("--------------[ Help ]--------------\n");
			printf("-h, --help   Show this menu\n");
			printf("-m           Show memory info\n");
			printf("-p n         Print n numbers\n");
			printf("-s n         Set array size\n");
			printf("-t           Show run time\n");
			printf("-i a b       Set interval\n");
			printf("-r n         Set seed\n");
			printf("------------------------------------\n");

			return 0;
		}
		else if (((flags >> 0) & 1) == 0 && strcmp(argv[i], "-m") == 0) flags += 1u << 0;
		else if (((flags >> 1) & 1) == 0 && strcmp(argv[i], "-t") == 0) flags += 1u << 1;
		else if (strcmp(argv[i], "-r") == 0 && i + 1 < argc && sscanf (argv[i + 1], "%u", &seed) == 1) i++;
		else if (strcmp(argv[i], "-i") == 0 && i + 2 < argc && sscanf (argv[i + 1], "%lf", &min_value) == 1 && sscanf (argv[i + 2], "%lf", &max_value) == 1) i += 2;
		else if (strcmp(argv[i], "-p") == 0 && i + 1 < argc && sscanf (argv[i + 1], "%lu", &printed_count) == 1) i++;
		else if (strcmp(argv[i], "-s") == 0 && i + 1 < argc && sscanf (argv[i + 1], "%lu", &array_size) == 1) {
			if (array_size < ARRAY_SIZE) {
				printf ("Invalid argument\n");
				return WRONG_ARGS;
			}
			i++;
		}
		else {
			printf("Unknown parameter: %s\n", argv[i]);
			return UNKNOW_ARG;
		}
    	}
    	
	srand (seed);
	array = (double*) malloc (array_size * sizeof (double));
	if (!array) {
		printf ("Not enough memory\n");
		return MEMORY_ERROR;
	}
    	if ((flags >> 0) & 1)
		printf ("%lu bytes have been allocated to store %lu numbers\n", array_size * sizeof (double), array_size);
	
	show_time = ((flags >> 1) & 1) ? 1 : 0;
	
	test (array, array_size, printed_count, show_time, min_value, max_value, 1, multiply_2);
	test (array, array_size, printed_count, show_time, min_value, max_value, 2, logarithm);
	test (array, array_size, printed_count, show_time, min_value, max_value, 3, sign);
	test (array, array_size, printed_count, show_time, min_value, max_value, 4, power);
	test (array, array_size, printed_count, show_time, min_value, max_value, 5, root);
	test (array, array_size, printed_count, show_time, min_value, max_value, 6, negative);
	test (array, array_size, printed_count, show_time, min_value, max_value, 7, division);
	
	free (array);
	return 0;
}

