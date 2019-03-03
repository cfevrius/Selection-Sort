#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

int main(int argc, char* argv[]){

    int data_to_sort[] = { 34, 23, 22, 8, 50, 74, 2, 1, 17, 40 };
    int node_elements = 10;

    List* l = list_create();

    /* Loop through all elements of the array and add 
     * them to the linked-List. */
    for(int i = 0; i < node_elements; i++){
        list_insert(l, data_to_sort[i]);
    }

    list_display(l);
    list_sort(l);
    list_display(l);

    list_destroy(l);
    return 0;
}
