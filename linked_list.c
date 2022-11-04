#include <stdio.h>
#include <stdlib.h>


int hello_world() {
   // printf() displays the string inside quotation
   printf("Hello, World!\n");
   
   return 0;
}

struct node_type {
    int value;
    struct node_type* next_value;
};

typedef struct node_type node;


// Create linked list from values accepted from user
void create_list(node* head, int size) {
    int input;
    node* current = NULL;
    node* next_node = NULL;
   
    for (int i = 0; i < size; i++) {

        printf("Enter a value to input in the list: \n");
        scanf("%d", &input);

        if (!current) {
            current = head;
            current -> value = input;
            current -> next_value = NULL;
        }
        else {
            next_node = malloc(sizeof(node));

            next_node -> value = input;
            next_node -> next_value = NULL;
            current -> next_value = next_node;
            current = current -> next_value;
        }

    }
}

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

// Add node at start
void add_head(node** head, int value) {
    node* target_head = malloc(sizeof(node));
    target_head -> value = value;
    target_head -> next_value = *head;
    *head = target_head;
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


// Add  a node to  a list
void insert_node(node** head, int position, int value) {

   node* to_add = malloc(sizeof(node));

   node* current = get_node(*head, position);
   node* next_node = current -> next_value;

   to_add -> value = value;
   to_add -> next_value = next_node;
   current -> next_value = to_add;
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
   node* head = malloc(sizeof(node));
   node** head_pointer = &head;
   create_list(head, 3);
   print_length(head);
   printf("smth");
   insert_node(head_pointer, 3, 5);
}
