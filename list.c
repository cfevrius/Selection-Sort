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
    (l->size)++;
}

void swap(List* l, Node* node1, Node* node2){
    // printf("Swapping %d with %d\n", node1->data, node2->data);
    Node* orig_next_node1 = node1->next;
    Node* orig_prev_node1 = node1->prev;
    Node* orig_next_node2 = node2->next;
    Node* orig_prev_node2 = node2->prev;   

    /* first node is head */
    if(orig_prev_node1 == 0){
        l->head = node2;
        node2->prev = NULL;
    /* first node is not head */
    }else{
        node2->prev = orig_prev_node1;
        orig_prev_node1->next = node2;
    }
    /* nodes are next to each other */
    if(node2 == orig_next_node1){
        node1->prev = node2;
        node2->next = node1;
    /* nodes are not next to each other */
    } else {
        node1->prev = orig_prev_node2;
        node2->next = orig_next_node1; 
 
        orig_prev_node2->next = node1;
        orig_next_node1->prev = node2;
    }
    /* second node is tail */
    if(orig_next_node2 == 0){
        node1->next = 0;
    /* second node is not tail */
    } else{
        node1->next = orig_next_node2;
        orig_next_node2->prev = node1;
    } 
}

void  list_sort(List* l){
    Node* offset = l->head;
    
    for(int i = 0; i < (l->size) && offset; i++){
        int min        = offset->data;
        Node* min_addr = offset;
        Node* orig_offset_next = offset->next;
        for(Node* curr = offset; curr; curr = curr->next){
            if(curr->data < min){
                min_addr = curr;
                min = curr->data;
            }
        }
        if(min_addr != offset){
            swap(l, offset, min_addr);
        }
        offset = orig_offset_next;
        if(min_addr == orig_offset_next){
            offset = offset->next;
        }
    }
}

void delete(Node* curr){
    Node* orig_next_next = curr->next->next; 
    node_destroy(curr->next);
    if(orig_next_next){
        curr->next = orig_next_next;
        orig_next_next->prev = curr;
    } else {
        curr->next = 0;
    }
}

void list_remove_duplicates(List* l){
    bool deleted = true;
    while(deleted){
        deleted = false;
        for(Node* curr = l->head; curr; curr = curr->next){
            if(curr->next && curr->data == curr->next->data){
                delete(curr);
                (l->size)--;
                deleted = true;
            }
        }
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
