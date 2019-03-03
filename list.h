#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct List List;
struct List {
    Node* head;
    Node* tail;
};

List* list_create();
void  list_display(List* l);
void  list_insert(List* l, int i);
void  list_sort(List* l);
void  list_destroy(List* l);

#endif
