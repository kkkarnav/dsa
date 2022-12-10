#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct queue_type {
    int front;
	int rear;
	int current_size;
	int capacity;
	int* values;
};

typedef struct queue_type queue;


queue* create_queue(int capacity) {

    queue* queue_obj = (queue*) malloc(sizeof(struct queue_type));

	queue_obj -> capacity = capacity;
	queue_obj -> size = 0;
	queue_obj -> front = 0;
	queue_obj -> rear = capacity - 1;
	queue_obj -> values = (int*) malloc(queue_obj -> capacity * sizeof(int));

	return queue_obj;
}

void print_queue(queue* queue_obj) {

	for (int i = queue_obj -> rear; i >= front; i--) {
		printf("%d, ", queue_obj -> values[i]);
	}
}

int main() {

	int size = 5;
	int* array = create_array(size);
	print_array(array, size);

    queue* queue_obj = create_queue(size);
    print_queue(queue_obj);
	printf("\n");

    return 0;
}
