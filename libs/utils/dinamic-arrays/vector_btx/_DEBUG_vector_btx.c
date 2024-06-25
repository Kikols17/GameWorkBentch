/* BTX_DEBUG FILE FOR "vector_btx.c"
 */


#include <stdlib.h>

#include "vector_btx.h"
#include "../../comparisons/cmp_btx.h"

int main() {
    vector_btx *v = init_vectorbtx(sizeof(int));
    if (v==NULL) {
        printf("Failed to create vector_btx\n");
        return 1;
    }
    for (int i=10; i>0; i--) {
        push_vectorbtx(v, &i);
    }


    printf("Unsorted v1: ");
    printf("size: %ld     capacity: %ld\n", v->size, v->capacity);
    for (size_t i=0; i<v->size; i++) {
        int element;
        get_vectorbtx(v, i, &element);
        printf("%d ", element);
    }
    printf("\n\n");


    if (sort_vectorbtx(v, int_cmpbtx) != 0) {
        printf("Failed to sort vector_btx\n");
        return 1;
    }
    printf("Sorted v1: ");
    printf("size: %ld     capacity: %ld\n", v->size, v->capacity);
    for (size_t i=0; i<v->size; i++) {
        int element;
        get_vectorbtx(v, i, &element);
        printf("%d ", element);
    }
    printf("\n\n");


    vector_btx *v2 = init_vectorbtx(sizeof(int));
    if (v2==NULL) {
        printf("Failed to create vector_btx\n");
        return 1;
    }
    for (int i=0; i<30; i++) {
        push_vectorbtx(v2, &i);
    }

    printf("Unsorted v2: ");
    printf("size: %ld     capacity: %ld\n", v2->size, v2->capacity);
    for (size_t i=0; i<v2->size; i++) {
        int element;
        get_vectorbtx(v2, i, &element);
        printf("%d ", element);
    }
    printf("\n\n");



    printf("Pop v2 (5x): ");
    int element;
    for (int i=0; i<5; i++) {
        pop_vectorbtx(v2, &element);
        printf("%d ", element);
    }
    printf("\n\n");



    if (append_vectorbtx(v, v2) != 0) {
        printf("Failed to append vector_btx\n");
        return 1;
    }
    printf("Appended v1 (v1+v2): ");
    printf("size: %ld     capacity: %ld\n", v->size, v->capacity);
    for (size_t i=0; i<v->size; i++) {
        int element;
        get_vectorbtx(v, i, &element);
        printf("%d ", element);
    }
    printf("\n\n");

    element = 15;
    if ( find_vectorbtx(v, &element, int_cmpbtx) == -3 ) {
        printf("Element %d not found in vector_btx\n", element);
    } else {
        printf("Element %d found in vector_btx\n", element);
    }

    free_vectorbtx(v);
    free_vectorbtx(v2);


    return 0;
}