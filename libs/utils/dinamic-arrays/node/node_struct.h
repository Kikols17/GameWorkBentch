#ifndef NODE_STRUCT_H
#define NODE_STRUCT_H


// Define the structure of a node, points to the next node and to an unknown data type
typedef struct node {
    void *data;
    struct node *next;
} Node;


Node *create_node(void *data);
int destroy_node(Node *node);


#endif // NODE_STRUCT_H