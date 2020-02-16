#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct List List;
struct List {
    Node* head;
    Node* tail;
    int size;
};

List* list_create();
void  list_display(List* l);
void  list_append(List* l, int i);
void  list_sort(List* l);
void  list_remove_duplicates();
void  list_destroy(List* l);

#endif
