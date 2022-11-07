#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct tree_node_type {
    int value;
    struct tree_node_type* left;
    struct tree_node_type* right;
};

typedef struct tree_node_type node;

node* construct_node(int value) {
    node* construct = malloc(sizeof(node));

    construct -> value = value;
    construct -> left = NULL;
    construct -> right = NULL;

    return construct;
}

node* insert(node* root, int value) {

    if (!root) {
        return construct_node(value);
    } 
	else if (value < root -> value) {
        root -> left = insert(root -> left, value);
    } 
	else if (value > root -> value ) {
        root -> right = insert(root -> right, value);
    }

    return root;
}

node* create_tree(int* array, int length) {

    node* root = NULL;

    if (length != 0) {

        root = construct_node(array[0]);

        for (int i = 0; i < length; i++) {
            root = insert(root, array[i]);
        }
    }

    return root;
}

void print_inorder(node* root) {

	if(root -> left) {
        printf("(");
        print_inorder(root -> left);
        printf(")");
    }

    if (root) {
        printf(" %d ", root -> value);
    }

    if (root -> right) {
        printf("(");
        print_inorder(root -> right);
        printf(")");
    }
}

void print_preorder(node* root) {

    if (root) {
        printf("%d, ", root -> value);
    }
	
	if(root -> left) {
        print_preorder(root -> left);
    }

    if (root -> right) {
        print_preorder(root -> right);
    }
}

node* search(node* root, int value) {

    if (!root) {
        return root;
    }
	else if (value < root -> value) {
        return search(root -> left, value);
    }
	else if(value > root -> value ) {
        return search(root -> right, value);
    }
	else {
        return root;
    }
}

node* get_minimum(node* root) {

    node* current = root;

    if (!(current -> left)) {
        return current;
    }
	else {
        return get_minimum(current -> left);
    }
}

node* delete(node* root, int value) {
    
	if (!root) {
        return root;
    }
	else if (value > root -> value) {
        root -> right = delete(root -> right, value);
    }
	else if (value < root -> value) {
        root -> left = delete(root -> left, value);
    }
	else {
        node* _ = NULL;

        if (!(root -> left) && !(root -> right)) {
            free(root);
            return _;
        }
		else if (!(root->left)) {
            _ = root -> right;
            free(root);
            return _;
        }
		else if (!(root->right)) {
            _ = root -> left;
            free(root);
            return _;
        }
		else {
            node* successor = get_minimum(root);
            root -> value = successor -> value;
            free(successor);
        }
    }

    return root;
}

int main() {

	int size = 5;
	int* array = create_array(size);
	print_array(array, size);

    node* root = create_tree(array, size);
    print_inorder(root);
	printf("\n");

    return 0;
}
