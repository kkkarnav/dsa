#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "array.h"


void swap(int* a, int* b) {
  int _ = *a;
  *a = *b;
  *b = _;
}

int partition_array(int* array, int low, int high) {
  
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {

        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    
    return (i + 1);
}

int* quicksort_array(int* array, int low, int high) {
    if (low < high) {
    
        int pivot = partition_array(array, low, high);
    
        quicksort_array(array, low, pivot - 1);
        quicksort_array(array, pivot + 1, high);
    }

    return array;
}

int get_length(node* head) {
    int length = 0;

    for (node* i = head; i != NULL; i = i -> next_value) {
        length++;
    }

    return length;
}


// Get a node from a list
node* get_node(node* head, int position) {
    node* target = head;

    for(int i = 0; i < position; i++) {

        target = target -> next_value;

        if (!target) {
            return NULL;
        }
    }

    return target;
}

node* partition_list(node* low, node* high) {
    node* pivot = low;
    node* current = low;
    node* sorted = low;

    while (current && current != high) {
        if (current -> value < high -> value) {

            pivot = sorted;

            int _ = sorted -> value;
            sorted -> value = current -> value;
            current -> value = _;

            sorted = sorted -> next_value;
        }

        current = current -> next_value;
    }

    int _ = sorted -> value;
    sorted -> value = high -> value;
    high -> value = _;

    return pivot;
}

void quicksort_list(node* low, node* high) {
    if (low != high) {
        node* pivot = partition_list(low, high);

        if (pivot && pivot != low) {
            quicksort_list(low, pivot);
        }
        
        if (pivot && pivot -> next_value) {
            quicksort_list(pivot -> next_value, high);
        }
    }
}


int main() {

   /*int size = 3;
   int* array = create_array(size);
   print_array(array, size);

   array = quicksort_array(array, 0, size);
   print_array(array, size);*/

   node* head = create_list(4);
   print_list(head);

   quicksort_list(head, get_node(head, get_length(head)-1));
   print_list(head);

}
