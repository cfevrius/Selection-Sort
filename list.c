#ifndef LIST_C
#define LIST_C

#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

List* list_create(){
    List* l = calloc(1, sizeof(List));
    return l;
}

void  list_display(List* l){
    printf("List = [");
    Node* curr;
    for(curr = l->head; curr != NULL; curr = curr->next){
        if(curr->next == NULL){
            printf(" %d ", curr->data); 
        } else {
            printf(" %d,", curr->data); 
        }
    }
    printf("]\n");
}

void  list_append(List* l, int i){
    Node* new_node =  node_create(i);
    if (l->head == NULL) {
        l->head = new_node;
        l->tail = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    } else {
        l->tail->next = new_node;
        new_node->prev = l->tail;
        l->tail = new_node;
        new_node->next = NULL;
    }
}

void  list_sort(List* l){
    bool swapped = true;
    while ( swapped ){
        swapped = false;
        for(Node* curr = l->head; curr->next != NULL; curr = curr->next){
            if( (curr->data) > (curr->next->data) ){
                
                Node* first = curr->prev;                
                Node* last  = curr->next->next;

                Node* node1 = curr;
                Node* node2 = curr->next; 
               
                if(node1->prev == NULL){
                    l->head = node2;
                }  

                node2->prev = first;
                node2->next = node1;

                node1->prev = node2;
                node1->next = last; 
                 
                if(first) {
                    first->next = node2;
                }
                
                if(last)
                    last->prev = node1;

                curr = node2;
                swapped = true;
            }
        }
    }
}

void  list_destroy(List* l){
    Node* curr = l->head;
    while(curr != NULL){
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(l);
}

#endif
