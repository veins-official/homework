#ifndef FUNCTION_APPLIIER_H
#define FUNCTION_APPLIIER_H

typedef double (*unary_function) (double);
int apply_function (double*, size_t, unary_function);

#endif

