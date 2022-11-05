#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

//Chunk reverse the list
node* chunk_reverse(node** head, int k) {

    node* current = *head;
    node* next = NULL;
    node* previous = NULL;
	int counter = 0;

	while (current && counter < k) {
		next = current -> next_value;
		current -> next_value = previous;
        previous = current;
        current = next;
		counter += 1;
	}

	if (next != NULL) {
		(*head) -> next_value = chunk_reverse(&next, k);
	}

    (*head) = previous;
	return previous;

}

int main() {

   node* head = create_list(8);
   print_list(head);

   head = chunk_reverse(&head, 3);
   print_list(head);
}
