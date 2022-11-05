#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "array.h"


int* insertionsort_array(int* array, int size) {

    for (int i = 1; i < size; i++) {

        int key = array[i];
        int j = i - 1;

        for (int j = i - 1; j >= 0; j--) {
            if (key < array[j]) {
                array[j+1] = array[j];
            }
        }

        array[j + 1] = key;
    }

    return array;
}

node* insertionsort_list(node* head) {

	node* position = head;
  node* new_head = NULL;

	while (position) {
      node* next_node = position -> next_value;

      if (new_head == NULL || position -> value <= new_head -> value) {
          position -> next_value = new_head;
          new_head = position;
      }
      else {
          node* temp = new_head;
          while (temp -> next_value != NULL && temp -> next_value -> value < position -> value) {
              temp = temp -> next_value;
          }
          position -> next_value = temp -> next_value;
          temp -> next_value = position;
      }
      position = next_node;
	}

  head = new_head;
	return head;
}

int main() {

   /*int size = 3;
   int* array = create_array(size);
   print_array(array, size);

   array = insertionsort_array(array, size);
   print_array(array, size);*/

   node* head = create_list(4);
   print_list(head);

   head = insertionsort_list(head);
   print_list(head);

}
