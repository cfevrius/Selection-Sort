#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

void test_list(int* data_to_sort, int node_elements){
    List* l = list_create();

    /* Loop through all elements of the array and add 
     * them to the linked-List. */
    for(int i = 0; i < node_elements; i++){
        list_append(l, data_to_sort[i]);
    }
    
    list_display(l);
    list_sort(l);
    printf("Sorted ");
    list_display(l);
    printf("\n");

    printf("Removed Duplicate ");
    list_remove_duplicates(l);
    list_display(l);

    list_destroy(l);
    
}

int main(int argc, char* argv[]){

    int data_to_sort[] = { 7, 4, 8, 5, 8, 8, 0, 1, 1 };
    int node_elements = 9;
    test_list(data_to_sort, node_elements);

    /*
    
    int data_to_sort2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int node_elements2 = 10; 
    test_list(data_to_sort2, node_elements2);    

    int data_to_sort3[] = {5, 1, 4, 2, 3};
    int node_elements3 = 5;
    test_list(data_to_sort3, node_elements3);
   
    int data_to_sort4[] = { 34, 23 };
    int node_elements4 = 2;  
    test_list(data_to_sort4, node_elements4);
    */

    return 0;
}
