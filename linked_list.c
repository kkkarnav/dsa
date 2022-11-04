// An implementatioin of a linked list in C
// with functions to: 
// create the list from user-input values
// print the list
// get the length of the list or a node in it
// add a node at the start, middle or end
// delete a node from the list

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Print list length
int get_length(node* head) {
    int length = 0;

    for (node* i = head; i != NULL; i = i -> next_value) {
        length++;
    }

    // printf("Length of the list is ");
    // printf("%d \n", length);
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


// Add node at start
void add_head(node** head, int value) {
    node* target_head = malloc(sizeof(node));
    target_head -> value = value;
    target_head -> next_value = *head;
    *head = target_head;
}

// Add node at end
void add_last(node** current, int value)
{
   node* target_last = malloc(sizeof(node));
   node* last = *current;
   
   target_last -> value = value;
   target_last -> next_value = NULL;
   
   if (!*current)
   {
      *current = target_last;
      return;
   }
   
   while (last -> next_value != NULL)
   {
      last = last -> next_value;
   }
   
   last -> next_value = target_last;
}

// Add node in the middle
void insert_node(node* target, int value)
{
   if (target) {
      node* new_node = malloc(sizeof(node));
      new_node -> value = value;
      
      new_node -> next_value = target -> next_value;
      target -> next_value = new_node;
   }
}


// Delete a node from a list
void delete_node(node** head, int position) {
    node* to_delete = get_node(*head, position);

    if (position == 0) {
        *head = to_delete -> next_value;
        free(to_delete);
    } 
    else {
        node* previous = get_node(*head, position-1);
        previous -> next_value = to_delete -> next_value;
        free(to_delete);
    }
}

int main() {

   node* head = create_list(3);
   print_list(head);

   insert_node(get_node(head, 1), 5);
   print_list(head);
   
   delete_node(&head, 0);
   print_list(head);
}
