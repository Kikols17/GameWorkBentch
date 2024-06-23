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
     *      Returns:
     *          - NULL (if the vector_btx could not be created)
     *          - [valid pointer] (if the vector_btx was created successfully)
     */
    return init_vectorbtx_capacity(1, datatype_size);
}

vector_btx *init_vectorbtx_capacity(size_t capacity, size_t datatype_size) {
    /* Creates a vector_btx with the specified capacity that can store elements of the specified size
     * 
     *      Arguments:
     *          - capacity (size_t): the initial capacity of the vector_btx
     * 
     *      Returns:
     *          - NULL (if the vector_btx could not be created)
     *          - [valid pointer] (if the vector_btx was created successfully)
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
     *          - v (vector_btx *): the vector_btx to be destroyed
     * 
     *      Returns:
     *          - 0 (if the vector_btx was destroyed successfully)
     *          - 1 (if the vector_btx could not be destroyed)
     */
    if (v==NULL) {
        return 1;
    }
    if (v->data==NULL) {
        return 1;
    }
    free(v->data);
    free(v);
    return 0;
}


int push_vectorbtx(vector_btx *v, void *element) {
    /* Pushes an element to the end of the vector_btx
     * extends the vector_btx if the capacity is reached
     * 
     *      Arguments:
     *          - v (vector_btx *): the vector_btx to which the element will be pushed
     *          - element (void *): the element to be pushed
     * 
     *      Returns:
     *          - 0 (if the element was pushed successfully)
     *          - 1 (if the element could not be pushed)
     */
    if (v==NULL) {
        return 1;
    }
    if (v->data==NULL) {
        return 1;
    }
    if (v->size >= v->capacity) {
        v->data = realloc(v->data, 2*(v->capacity)*(v->datatype_size));
        if (v->data == NULL) {
            return 1;
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
     * 
     *      Arguments:
     *          - v (vector_btx *): the vector_btx from which the element will be popped
     *          - element (void *): the element to be popped
     * 
     *      Returns:
     *          - 0 (if the element was popped successfully)
     *          - 1 (if the element could not be popped)
     */
    if (v==NULL) {
        return 1;
    }
    if (v->data==NULL) {
        return 1;
    }
    if (v->size == 0) {
        return 1;
    }
    void *src = v->data + (v->size-1)*(v->datatype_size);
    memcpy(element, src, v->datatype_size);
    v->size--;
    return 0;
}


int get_vectorbtx(vector_btx *v, size_t index, void *element) {
    /* Gets an element from the vector_btx at the specified index
     * 
     *      Arguments:
     *          - v (vector_btx *): the vector_btx from which the element will be retrieved
     *          - index (size_t): the index of the element to be retrieved
     *          - element (void *): the element to be retrieved
     * 
     *      Returns:
     *          - 0 (if the element was retrieved successfully)
     *          - 1 (if the element could not be retrieved)
     */
    if (v==NULL) {
        return 1;
    }
    if (v->data==NULL) {
        return 1;
    }
    if (index >= v->size) {
        return 1;
    }
    void *src = v->data + index*(v->datatype_size);
    memcpy(element, src, v->datatype_size);
    return 0;
}

int set_vectorbtx(vector_btx *v, size_t index, void *element) {
    /* Sets an element in the vector_btx at the specified index
     * 
     *      Arguments:
     *          - v (vector_btx *): the vector_btx in which the element will be set
     *          - index (size_t): the index of the element to be set
     *          - element (void *): the element to be set
     * 
     *      Returns:
     *          - 0 (if the element was set successfully)
     *          - 1 (if the element could not be set)
     */
    if (v==NULL) {
        return 1;
    }
    if (v->data==NULL) {
        return 1;
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
     *          - v (vector_btx *): the vector_btx to be sorted
     *          - compare (int (*)(const void *, const void *)): the comparison function
     * 
     *      Returns:
     *          - 0 (if the vector_btx was sorted successfully)
     *          - 1 (if the vector_btx could not be sorted)
     */
    if (v==NULL) {
        return 1;
    }
    if (v->data==NULL) {
        return 1;
    }
    if (compare==NULL) {
        // if no comparison function is provided, use the default comparison function
        compare = &memcmp;
    }
    qsort(v->data, v->size, v->datatype_size, compare);
    return 0;
}

#endif // VECTOR_BTX_C