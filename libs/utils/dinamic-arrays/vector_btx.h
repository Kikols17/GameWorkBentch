#ifndef VECTOR_BTX_H
#define VECTOR_BTX_H

#include <stdlib.h>


// Define the vector_btx_t struct with a pointer to an array of undefined size and data type
typedef struct vector_btx {
    void *data;             // Pointer to the buffer array of elements of size datatype_size
    size_t datatype_size;   // Size of the data type in bytes (NOTE: ALTERING THIS VALUE AFTER INIT WILL CAUSE UNDEFINED BEHAVIOR)
    size_t size;            // Number of elements currently in the vector_btx
    size_t capacity;        // Current capacity of the vector_btx's buffer (data)
} vector_btx;


/* Create new vectorbtx */
vector_btx *init_vectorbtx(size_t datatype_size);
vector_btx *init_vectorbtx_capacity(size_t capacity, size_t datatype_size);
vector_btx *copy_vectorbtx(vector_btx *v);


/* Free vectorbtx */
int free_vectorbtx(vector_btx *v);


/* Increase/Decrease size (and capacity) of the vectorbtx */
int push_vectorbtx(vector_btx *v, const void *element);
int pop_vectorbtx(vector_btx *v, void *element);
int adjust_vectorbtx(vector_btx *v);
int append_vectorbtx(vector_btx *v, vector_btx *v2);


/* Get/Set values by array index on the vectorbtx */
int get_vectorbtx(vector_btx *v, size_t index, void *element);
int set_vectorbtx(vector_btx *v, size_t index, const void *element);


/* Search elements in the vectorbtx */
int sort_vectorbtx(vector_btx *v, int (*compare)(const void *, const void *));
int find_vectorbtx(vector_btx *v, const void *element, int (*compare)(const void *, const void *));



#endif // VECTOR_BTX_H