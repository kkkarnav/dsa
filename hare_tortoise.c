#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void hare_tortoise(node* head) {

    node* hare = head;
    node* tortoise = head;

    while (hare) {

        printf("%d, ", tortoise -> value);

        tortoise = tortoise -> next_value;
		if (hare -> next_value) {
			hare = hare -> next_value -> next_value;
		}
		else {
			hare = NULL;
		}
    }
}


int main() {

   node* head = create_list(6);
   print_list(head);

   hare_tortoise(head);

   return 0;
}
