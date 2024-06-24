#ifndef VECTOR_BTX_C
#define VECTOR_BTX_C

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "vector_btx.h"

vector_btx *init_vectorbtx(size_t datatype_size) {
    /* Creates a vector_btx with initial capacity=1, that can store elements of the specified size
     * This is the same as calling create_vectorbtx_capacity(1)
     *
     *      Arguments:
     *          -> datatype_size (size_t): the size of the data type in bytes
     *
     *      Returns:
     *          -> NULL (if the vector_btx could not be created)
     *          -> [valid pointer] (if the vector_btx was created successfully)
     */
    return init_vectorbtx_capacity(1, datatype_size);
}

vector_btx *init_vectorbtx_capacity(size_t capacity, size_t datatype_size) {
    /* Creates a vector_btx with the specified capacity that can store elements of the specified size
     * 
     *      Arguments:
     *          -> capacity (size_t): the initial capacity of the vector_btx
     *          -> datatype_size (size_t): the size of the data type in bytes
     * 
     *      Returns:
     *          -> NULL (if the vector_btx could not be created)
     *          -> [valid pointer] (if the vector_btx was created successfully)
     */
    vector_btx *v = (vector_btx*)malloc(sizeof(vector_btx));
    if (v == NULL) {
        return NULL;
    }
    v->data = malloc( capacity*datatype_size );
    if (v->data == NULL) {
        free(v);
        return NULL;
    }
    v->datatype_size = datatype_size;
    v->size = 0;
    v->capacity = capacity;
    return v;
}

int free_vectorbtx(vector_btx *v) {
    /* Destroys the vector_btx and frees the memory allocated for it
     * 
     *      Arguments:
     *          -> v (vector_btx *): the vector_btx to be destroyed
     * 
     *      Returns:
     *          -> -2 (if vector_btx structure is broken)
     *          -> 1 (if invalid vector_btx pointer)
     *          -> 0 (if the vector_btx was destroyed successfully)
     */
    if (v==NULL) {
        return -1;
    }
    if (v->data==NULL) {
        return -2;
    }
    free(v->data);
    free(v);
    return 0;
}


int push_vectorbtx(vector_btx *v, const void *element) {
    /* Pushes an element to the end of the vector_btx
     * extends the vector_btx if the capacity is reached
     * 
     *      Arguments:
     *          - v (vector_btx *): the vector_btx to which the element will be pushed
     *          - element (void *): the element to be pushed
     * 
     *      Returns:
     *          -> -2 (if the vector_btx structure is broken)
     *          -> -1 (if the vector_btx pointer is invalid)
     *          -> 0 (if the element was pushed successfully)
     */
    if (v==NULL) {
        return -1;
    }
    if (v->data==NULL) {
        return -2;
    }
    if (v->size >= v->capacity) {
        v->data = realloc(v->data, 2*(v->capacity)*(v->datatype_size));
        if (v->data == NULL) {
            return -1;
        }
        v->capacity *= 2;
    }
    void *dest = v->data + v->size*(v->datatype_size);
    memcpy(dest, element, v->datatype_size);
    v->size++;
    return 0;
}

int pop_vectorbtx(vector_btx *v, void *element) {
    /* Pops an element from the end of the vector_btx
     * Resizes the vector_btx if the size is less than half the capacity
     * 
     *      Arguments:
     *          -> v (vector_btx *): the vector_btx from which the element will be popped
     *          -> element (void *): the element to be popped
     * 
     *      Returns:
     *          -> -2 (if the vector_btx structure is broken)
     *          -> -1 (if the element could not be popped)
     *          -> 0 (if the element was popped successfully)
     */
    if (v==NULL) {
        return -1;
    }
    if (v->data==NULL) {
        return -2;
    }
    if (v->size == 0) {
        return -1;
    }
    void *src = v->data + (v->size-1)*(v->datatype_size);
    memcpy(element, src, v->datatype_size);
    v->size--;

    if (v->size <= ((v->capacity)/2)-((v->capacity)/4)  &&  v->capacity > 1) {
        // if the size is less than half the capacity, resize the vector_btx
        v->data = realloc(v->data, (v->capacity/2)*(v->datatype_size));
        if (v->data == NULL) {
            return -2;
        }
        v->capacity /= 2;
    }
    return 0;
}

int adjust_vectorbtx(vector_btx *v) {
    /* Forces the vector to have the minimum capacity required to store the current number of elements
     * 
     *      Arguments:
     *          -> v (vector_btx *): the vector_btx to be adjusted
     * 
     *      Returns:
     *          -> -2 (if the vector_btx structure is broken)
     *          -> -1 (if the vector_btx pointer is invalid)
     *          -> 0 (if the vector_btx was adjusted successfully)
     */
    if (v==NULL) {
        return -1;
    }
    if (v->data==NULL) {
        return -2;
    }
    while (v->size < v->capacity) {
        v->data = realloc(v->data, (v->capacity/2)*(v->datatype_size));
        if (v->data == NULL) {
            return -2;
        }
        v->capacity /= 2;
    }

    return 0;
}


int get_vectorbtx(vector_btx *v, size_t index, void *element) {
    /* Gets an element from the vector_btx at the specified index
     * 
     *      Arguments:
     *          -> v (vector_btx *): the vector_btx from which the element will be retrieved
     *          -> index (size_t): the index of the element to be retrieved
     *          -> element (void *): the element to be retrieved
     * 
     *      Returns:
     *          -> -2 (if the vector_btx structure is broken)
     *          -> -1 (if the element could not be retrieved)
     *          -> 0 (if the element was retrieved successfully)
     *          -> 1 (if the index is out of bounds)
     */
    if (v==NULL) {
        return -1;
    }
    if (v->data==NULL) {
        return -2;
    }
    if (index >= v->size) {
        return 1;
    }
    void *src = v->data + index*(v->datatype_size);
    memcpy(element, src, v->datatype_size);
    return 0;
}

int set_vectorbtx(vector_btx *v, size_t index, const void *element) {
    /* Sets an element in the vector_btx at the specified index
     * 
     *      Arguments:
     *          -> v (vector_btx *): the vector_btx in which the element will be set
     *          -> index (size_t): the index of the element to be set
     *          -> element (void *): the element to be set
     * 
     *      Returns:
     *          -> -2 (if the vector_btx structure is broken)
     *          -> -1 (if the element could not be set)
     *          -> 0 (if the element was set successfully)
     *          -> 1 (if the index is out of bounds)
     */
    if (v==NULL) {
        return -1;
    }
    if (v->data==NULL) {
        return -2;
    }
    if (index >= v->size) {
        return 1;
    }
    void *dest = v->data + index*(v->datatype_size);
    memcpy(dest, element, v->datatype_size);
    return 0;
}


int sort_vectorbtx(vector_btx *v, int (*compare)(const void *, const void *)) {
    /* Sorts the elements of the vector_btx using the specified comparison function, using the qsort function
     *
     *      Arguments:
     *          -> v (vector_btx *): the vector_btx to be sorted
     *          -> compare (int (*)(const void *, const void *)): the comparison function, NULL if default "cmp_btx" (memcmp)
     *
     *      Returns:
     *          -> -2 (if the vector_btx structure is broken)
     *          -> -1 (if the vector_btx pointer is invalid)
     *          -> 0 (if the vector_btx was sorted successfully)
     */
    if (v==NULL) {
        // invalid vector_btx pointer
        return -1;
    }
    if (v->data==NULL) {
        // invalid data pointer, vector_btx is broken
        return -2;
    }

    int (*func)(const void *, const void *);
    if (compare==NULL) {
        // if no comparison function is provided, use the default comparison function
        func = cmp_btx;
    } else {
        func = compare;
    }
    qsort(v->data, v->size, v->datatype_size, func);

    return 0;
}

int cmp_btx(const void *a, const void *b) {
    /* Default comparison function for the sort_vectorbtx function
     *
     *      Arguments:
     *          -> a (const void *): the first element to be compared
     *          -> b (const void *): the second element to be compared
     *
     *      Returns:
     *          -> -1 (if a < b)
     *          -> 0 (if a == b)
     *          -> 1 (if a > b)
     */
    return memcmp(a, b, sizeof(*a));
}


#endif // VECTOR_BTX_C