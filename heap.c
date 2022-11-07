#include <stdio.h>
#include <stdlib.h>
#include "array.h"


void swap(int* a, int* b) {
  int _ = *a;
  *a = *b;
  *b = _;
}

//Heapify
void heapify(int* array, int length, int root_idx) {

    int min_idx = root_idx;
    int left = root_idx*2+1;
    int right = root_idx*2+2;

    if (left < length && array[left] < array[min_idx]) {
        min_idx = left;
    }
	
	if (right < length && array[right] < array[min_idx]) {
        min_idx = right;
    }

    if (min_idx != root_idx) {
        swap(&array[root_idx], &array[min_idx]);
        heapify(array, length, min_idx);
    }
}

int* heap(int* array, int length) {

    int last_leaf = (length/2)-1;

    for (int i = last_leaf; i >= 0; i--) {
        heapify(array, length, i);
    }

	return array;
}

int* insert(int* array, int* size, int value) {
    int* new_array = realloc(array, sizeof(int)*(*size+1));
    new_array[*size] = value;
    heap(new_array, *size+1);
    *size = *size+1;
    return new_array;
}

int get_minimum(int* array, int size) {

    swap(&array[0], &array[(size)-1]);

    int minimum = array[size-1];

    heapify(array, size-1, 0);
    size = size - 1;
    return minimum;
}

void heapsort(int* heap, int size) {
    while(size > 0) {
        get_minimum(heap, size);
    }
}

int main() {

    int size = 3;
	int* array = create_array(size);
	print_array(array, size);

    array = heap(array, size);
    print_array(array, size);
    
    return 0;
}
