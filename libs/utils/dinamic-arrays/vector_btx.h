#ifndef VECTOR_BTX_H
#define VECTOR_BTX_H

#include <stdlib.h>


// Define the vector_btx_t struct with a pointer to an array of undefined size and data type
typedef struct vector_btx {
    void *data;
    size_t datatype_size;
    size_t size;
    size_t capacity;
} vector_btx;

vector_btx *init_vectorbtx(size_t datatype_size);
vector_btx *init_vectorbtx_capacity(size_t capacity, size_t datatype_size);
int free_vectorbtx(vector_btx *v);

int push_vectorbtx(vector_btx *v, void *element);
int pop_vectorbtx(vector_btx *v, void *element);

int get_vectorbtx(vector_btx *v, size_t index, void *element);
int set_vectorbtx(vector_btx *v, size_t index, void *element);

int sort_vectorbtx(vector_btx *v, int (*compare)(const void *, const void *));

#endif // VECTOR_BTX_H