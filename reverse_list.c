#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

//Reverse the list
void reverse(node** head) {

    node* current = *head;
    node* next = current -> next_value;
    node* previous = NULL;

    while (current) {
        next = current -> next_value;
        current -> next_value = previous;
        previous = current;
        current = next;
    }

    *head = previous;
}

int main() {

   node* head = create_list(3);
   print_list(head);

   reverse(&head);
   print_list(head);
}
