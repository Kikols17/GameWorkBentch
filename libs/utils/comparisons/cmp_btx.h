#ifndef CMP_BTX_H
#define CMP_BTX_H

#include <stdlib.h>


/* Comparison functions for the sort_vectorbtx function */
int mem_cmpbtx(const void *a, const void *b);
int int_cmpbtx(const void *a, const void *b);
int float_cmpbtx(const void *a, const void *b);

#endif // CMP_BTX_H