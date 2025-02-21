#include <math.h>

#include "unit_tests.h"


double multiply_2 (double a) {
	return a * 2;
}

double logarithm (double a) {
	if (a <= 0) return a;
	return log (a);
}

double sign (double a) {
	if (a > 0.0) return 1.0;
	if (a < 0.0) return -1.0;
	return 0.0;
}

double power (double a) {
	return a * a;
}

double root (double a) {
	if (a < 0) return a;
	return sqrt (a);
}

double negative (double a) {
	return a * -1.0;
}

double division (double a) {
	return a / 2;
}

