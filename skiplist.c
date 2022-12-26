#include <stdio.h>
#include <stdlib.h>

struct skip_node_type {
    int value;
    struct skip_node_type* next_value;
	struct skip_node_type* skip_next[2];
};

typedef struct skip_node_type node;

node* construct_node(int value) {
	node* construct = malloc(sizeof(node));

	construct -> value = value;
	construct -> next_value = NULL;
	construct -> skip_next[0] = NULL;
	construct -> skip_next[1] = NULL;

	return construct;
}

node* insert_node(node* head, int value) {

	node* current = head;
	int counter = 0;
	node* skip_1 = head;
	node* skip_2 = head;

	while (current -> next_value != NULL) {

		if (counter && counter % 5 == 0) {
			skip_1 -> skip_next[0] = current;
			skip_1 = current;
		}
		
		if (counter && counter % 10 == 0) {
			skip_2 -> skip_next[1] = current;
			skip_2 = current;
		}
		
		current = current -> next_value;
		counter += 1;
	}

	node* new_node = construct_node(value);
	current -> next_value = new_node;
	counter += 1;

    if (counter%5 == 0) {
        skip_1 -> skip_next[0] = new_node;
    }

	if (counter%10 == 0) {
        skip_2 -> skip_next[1] = new_node;
    }

	return head;

}

void print_list(node* head) {

    node* current = head;
    while (current) {
        printf("%d,", current -> value);
        current = current -> next_value;
    }
    printf("\n");

    current = head;
    while (current) {
        printf("%d,", current -> value);
        current = current -> skip_next[0];
    }
    printf("\n");

	current = head;
    while (current) {
        printf("%d,", current -> value);
        current = current -> skip_next[1];
    }
    printf("\n");

}
int main() {

    node* head = construct_node(0);
	for (int i = 1; i <= 19; i++) {
		head = insert_node(head, i);
	}

    print_list(head);

    return 0;
}
