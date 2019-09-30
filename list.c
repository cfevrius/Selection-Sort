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

void swap(Node* node1, Node* node2){
    Node* orig_prev_node1 = node1->prev;
    Node* orig_next_node2 = node2->next;
    node2->next = node1;
    node2->prev = orig_prev_node1;
    node1->next = orig_next_node2;
    node1->prev = node2;
}

void  list_sort(List* l){
    Node* offset = l->head;
    for(int i = 0; i < 9; i++){
        int min        = offset->data;
        Node* min_addr = offset;
        for(Node* curr = offset; curr; curr = curr->next){
            if(curr->data < min){
                min_addr = curr;
            }
        }
        swap(offset, min_addr);
        offset = offset->next;
    }
}

void  list_destroy(List* l){
    Node* curr = l->head;
    while(curr != NULL){
        Node* temp = curr;
        curr = curr->next;
        node_destroy(temp);
    }
    free(l);
}

#endif
