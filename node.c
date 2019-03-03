#ifndef NODE_C
#define NODE_C

#include "node.h"
#include "stdlib.h"

Node* node_create(int i){
    Node* n = calloc(1, sizeof(Node));
    n->data = i;
    return n;
}

void  node_destroy(Node* n){
    free(n);
}

#endif
