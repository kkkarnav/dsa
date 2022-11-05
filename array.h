#ifndef ARRAY_H_
#define ARRAY_H_

// Create array from values accepted from user
int* create_array(int size) {

	int* array = malloc(sizeof(size));
   
    for (int i = 0; i < size; i++) {
        printf("Enter a value to input in the list: \n");
        scanf("%d", &array[i]);
    }

	return array;
}

void print_array(int* array, int size) {

   printf("The list is: ");
   
   for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}
#endif
