#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;
struct node {
    node* prev;
    node* next;
    int data;
};

node* node_create(int i);
void  node_destroy(node* n);

typedef struct list list;
struct list {
    node* head;
    node* tail;
};

list* list_create();
void  list_display(list* l);
void  list_insert(list* l, int i);
void  list_sort(list* l);
void  list_destroy(list* l);

int main(int argc, char* argv[]){

    int data_to_sort[] = { 34, 23, 22, 8, 50, 74, 2, 1, 17, 40 };
    int node_elements = 10;

    list* l = list_create();

    /* Loop through all elements of the array and add 
     * them to the linked-list. */
    for(int i = 0; i < node_elements; i++){
        list_insert(l, data_to_sort[i]);
    }

    list_display(l);
    list_sort(l);
    list_display(l);

    list_destroy(l);
    return 0;
}

node* node_create(int i){
    node* n = calloc(1, sizeof(node));
    n->data = i;
    return n;
}


void  node_destroy(node* n){
    free(n);
}

list* list_create(){
    list* l = calloc(1, sizeof(list));
    return l;
}

void  list_display(list* l){
    printf("list = [");
    node* curr;
    for(curr = l->head; curr != NULL; curr = curr->next){
        if(curr->next == NULL){
            printf(" %d ", curr->data); 
        } else {
            printf(" %d,", curr->data); 
        }
    }
    printf("]\n");
}

void  list_insert(list* l, int i){
    node* new_node =  node_create(i);
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

void  list_sort(list* l){
    bool swapped = true;
    while ( swapped ){
        swapped = false;
        for(node* curr = l->head; curr->next != NULL; curr = curr->next){
            if( (curr->data) > (curr->next->data) ){
                
                node* first = curr->prev;                
                node* last  = curr->next->next;

                node* node1 = curr;
                node* node2 = curr->next; 
               
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
                
                if(last){ 
                    last->prev = node1;
                }                

                curr = node2;
                swapped = true;
            }
        }
    }
}

void  list_destroy(list* l){
    node* curr = l->head;
    while(curr != NULL){
        node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(l);
}
