#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "array.h"

// function to swap the the position of two elements
void swap(int *a, int *b) {
  int _ = *a;
  *a = *b;
  *b = _;
}

int* selectionsort_array(int* array, int size) {

  for (int i = 0; i < size - 1; i++) {

    int minimum = i;
    for (int j = i + 1; j < size; j++) {

      if (array[j] < array[minimum])
        minimum = j;
    }

    swap(&array[minimum], &array[i]);
  }

  return array;
}

node* selectionsort_list(node* head) {

	node* position = head;

	while (position) {
		node* minimum = position;
		node* minimum_next = position -> next_value;

		while (minimum_next) {
			if (minimum -> value > minimum_next -> value) {
				minimum = minimum_next;
			}
			minimum_next = minimum_next -> next_value;
		}

		int _ = position -> value;
		position -> value = minimum -> value;
		minimum -> value = _;
		position = position -> next_value;

	}
	return head;
}

int main() {

   /*int size = 3;
   int* array = create_array(size);
   print_array(array, size);

   array = selectionsort_array(array, size);
   print_array(array, size);*/

   node* head = create_list(4);
   print_list(head);

   head = selectionsort_list(head);
   print_list(head);

}
