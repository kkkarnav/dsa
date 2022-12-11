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
	queue_obj -> current_size = 0;
	queue_obj -> front = -1;
	queue_obj -> rear = -1;
	queue_obj -> values = (int*) malloc(queue_obj -> capacity * sizeof(int));

	return queue_obj;
}

int is_full(queue* queue_obj) {
	return (queue_obj -> current_size == queue_obj -> capacity);
}

int is_empty(queue* queue_obj) {
	return (queue_obj -> current_size == 0);
}

int update_size(int front, int rear) {
	return (front > rear ? (front - rear) : (rear - front));
}

queue* enqueue(queue* queue_obj, int value) {
	if (is_full(queue_obj) == 1) {
		return queue_obj;
	}

	queue_obj -> rear = ((queue_obj -> rear) + 1) % queue_obj -> capacity;
	queue_obj -> values[queue_obj -> rear] = value;
	queue_obj -> current_size = update_size(queue_obj -> front, queue_obj -> rear);

	printf("Enqueued %d \n", value);

	return queue_obj;
}

int dequeue(queue* queue_obj) {
	if (is_empty(queue_obj) == 1) {
		return -2147483648;
	}

	int value = queue_obj -> values[queue_obj -> front];
	queue_obj -> front = ((queue_obj -> front) + 1) % queue_obj -> capacity;
	queue_obj -> current_size = update_size(queue_obj -> front, queue_obj -> rear);

	printf("Dequeued %d \n", value);

	return value;
}

void print_queue(queue* queue_obj) {

	for (int i = 0; i < queue_obj -> capacity; i++) {
		printf("%d, ", queue_obj -> values[i]);
	}
}

int main() {

	int size = 5;
	int* array = create_array(size);
	print_array(array, size);

    queue* queue_obj = create_queue(size);
	for (int i = 0; i < size; i++) {
		enqueue(queue_obj, array[i]);
	}
    print_queue(queue_obj);
	printf("\n");

    return 0;
}
