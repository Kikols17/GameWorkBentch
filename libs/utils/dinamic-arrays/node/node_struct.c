#ifndef NODE_STRUCT_C
#define NODE_STRUCT_C

#include <stdlib.h>

#include "node_struct.h"


// create a new node
Node *create_node(void *data) {
    /* Allocate memory for a new node
     * Parameters:
     *      data -> the data to be stored in the node
     * Return:
     *      NULL -> (if memory allocation fails)
     *      [valid pointer] -> (if memory allocation is successful)
     */
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


// destroy a node
int destroy_node(Node *node) {
    /* Free the memory allocated for a node
     * Parameters:
     *      node -> the node to be freed
     * Return:
     *     -1 -> (if the node is NULL)
     *      0 -> (if the node is successfully freed)
     *
     * Notes: This function does not free the memory allocated for the data stored in the node.
     *        Destroying a node does not join the previous and next nodes.
     */
    if (node == NULL) {
        return -1;
    }
    free(node);
    return 0;
}

#endif // NODE_STRUCT_C