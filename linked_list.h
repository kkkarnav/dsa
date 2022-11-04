#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct node_type {
    int value;
    struct node_type* next_value;
};

typedef struct node_type node;
// Create linked list from values accepted from user
node* create_list(int size) {
    int input;
    
    node* head = malloc(sizeof(node));
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

    return head;
}

void print_list(node* head) {
   printf("The list is: ");
    while (head) {
        printf("%d, ", head -> value);
        head = head -> next_value;
    }
    printf("\n");
}
#endif
