#ifndef CMP_BTX_C
#define CMP_BTX_C

#include <stdlib.h>

#include "cmp_btx.h"



/* Comparison functions for the sort_vectorbtx function */
int mem_cmpbtx(const void *a, const void *b) {
    /* Default comparison function for the sort_vectorbtx function
     * Compares the elements using the memcmp function, not suitable for float elements
     *
     *      Arguments:
     *          -> a (const void *): the first element to be compared
     *          -> b (const void *): the second element to be compared
     *
     *      Returns:
     *          -> -2 (if a or b is NULL)
     *          -> -1 (if a < b)
     *          -> 0 (if a == b)
     *          -> 1 (if a > b)
     */
    if (a==NULL || b==NULL) {
        return -2;
    }

    return memcmp(a, b, sizeof(*a));
}

int int_cmpbtx(const void *a, const void *b) {
    /* Comparison function for the sort_vectorbtx function for int elements
     * Compares the elements using the int values
     *
     *      Arguments:
     *          -> a (const void *): the first element to be compared
     *          -> b (const void *): the second element to be compared
     *
     *      Returns:
     *          -> -2 (if a or b is NULL)
     *          -> -1 (if a < b)
     *          -> 0 (if a == b)
     *          -> 1 (if a > b)
     */
    if (a==NULL || b==NULL) {
        return -2;
    }

    int ia = *(int*)a;
    int ib = *(int*)b;
    if (ia < ib) {
        return -1;
    } else if (ia > ib) {
        return 1;
    } else {
        return 0;
    }
}

int float_cmpbtx(const void *a, const void *b) {
    /* Comparison function for the sort_vectorbtx function for float elements
     * Compares the elements using the float values
     *
     *      Arguments:
     *          -> a (const void *): the first element to be compared
     *          -> b (const void *): the second element to be compared
     *
     *      Returns:
     *          -> -2 (if a or b is NULL)
     *          -> -1 (if a < b)
     *          -> 0 (if a == b)
     *          -> 1 (if a > b)
     */
    if (a==NULL || b==NULL) {
        return -2;
    }

    float fa = *(float*)a;
    float fb = *(float*)b;
    if (fa < fb) {
        return -1;
    } else if (fa > fb) {
        return 1;
    } else {
        return 0;
    }
}


#endif // CMP_BTX_C