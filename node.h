#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
struct Node {
    Node* prev;
    Node* next;
    int data;
};

Node* node_create(int i);
void  node_destroy(Node* n);

#endif
