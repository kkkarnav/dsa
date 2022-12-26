#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct tree_node_type {
    int value;
    struct tree_node_type* left;
    struct tree_node_type* right;
	struct tree_node_type* parent;
	int solid;
};

typedef struct tree_node_type node;

node* construct_node(int value) {
    node* construct = malloc(sizeof(node));

    construct -> value = value;
    construct -> left = NULL;
    construct -> right = NULL;
	construct -> parent = NULL;
	construct -> solid = 0;

    return construct;
}

int get_balance(int left, int right) {
	return (left - right);
}

void switch_down(node* root) {
	if (!root) {
		return;
	}
	else {
		root -> solid = 0;
		if (root -> left && root -> left -> solid == 1) {
			switch_down(root -> left);
			return;
		}
		else if (root -> right) {
			switch_down(root -> right);
			return;
		}
	}
}

void switch_up(node* root, int value) {
	if (!root || !(root -> parent)) {
		return;
	}
	else if (root -> parent -> left && root -> parent -> left -> solid == 1 && root -> parent -> right && root -> parent -> right -> solid == 1) {
		if (root -> right && root -> parent -> left -> value > value) {
		    switch_down(root);
			return;
		}
		else if (root -> left && root -> parent -> right -> value < value) {
			switch_down(root);
			return;
		}
	}
	else {
		root -> parent -> solid = 1;
		switch_up(root -> parent, value);
	}
}

node* left_rotate(node* pivot) {
	node* right_node = pivot -> right;
	pivot -> right = right_node -> left;
	right_node -> left = pivot;
	return right_node;
}

node* right_rotate(node* pivot) {
	node* left_node = pivot -> left;
	pivot -> left = left_node -> right;
	left_node -> right = pivot;
	return left_node;
}

node* prefer(node* pivot, int value) {
    if (pivot -> value == value) {
        return pivot;
    }
    if (pivot -> left && pivot -> left -> solid) {
		return prefer(pivot -> left, value);
	}
	else if (pivot -> right && pivot -> right -> solid) {
		return prefer(pivot -> right, value);
	}
	return pivot;
}

node* splay(node* pivot, int value) {

	if (!pivot) {
		return pivot;
	}

    if (pivot -> value == value) {
		switch_up(pivot, value);
		return pivot;
	}
	
	if (pivot -> solid) {
		if (prefer(pivot, value) == value) {
		    return pivot;
		}
	}

	if (pivot -> value > value) {
	
		if (pivot -> left == NULL) {
			return pivot;
		}
		
		if (pivot -> left -> value > value) {
			
			pivot -> left -> left = splay(pivot -> left -> left, value);
			pivot = right_rotate(pivot);
		}
		
		else if (pivot->left->value < value) {
			
			pivot->left->right = splay(pivot->left->right, value);
			
			if (pivot->left->right != NULL) {
				pivot -> left = left_rotate(pivot->left);
			}
		}

		return (pivot->left == NULL)? pivot: right_rotate(pivot);
	}
	else {
		
		if (pivot->right == NULL) return pivot;

		if (pivot->right->value > value) {
			
			pivot->right->left = splay(pivot->right->left, value);

			if (pivot->right->left != NULL) {
				pivot->right = right_rotate(pivot->right);
			}
		
		}
		else if (pivot->right->value < value) {
			
			pivot->right->right = splay(pivot->right->right, value);
			pivot = left_rotate(pivot);
		}
		
		return (pivot->right == NULL)? pivot: left_rotate(pivot);
	}
}

node* search(node* root, int value) {

    splay(root, value);

}

node* insert(node* root, int value) {

	node* new_node = construct_node(value);
	int left = 0;

    if (!(root)) {
        return new_node;
    } 
	else {
		node* current = root;
		node* copy = root;
		node* leaf;

		while (current) {
			leaf = current;
			if (get_balance(new_node -> value, current -> value) < 0) {
				left = 1;
				current = current -> left;
			}
			else {
				current = current -> right;
			}
		}

		new_node -> parent = leaf;
		if (left) {
			leaf -> left = new_node;
		}
		else {
			leaf -> right = new_node;
		}
	}

	splay(new_node, new_node -> value);

    return root;
}

node* create_tree(int* array, int length) {

    node* root = NULL;

    if (length != 0) {

        root = construct_node(array[0]);

        for (int i = 1; i < length; i++) {
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

	root = splay(root, value);

	if (root -> value == value) {

        if (root -> left == NULL) {
            root = root -> right;
        }
        else{
            node* _ = root -> right;
            root = root -> left;

            root = splay(root, value);
            root -> right = _;
        }
    }

    return root;
}

int main() {

	int size = 5;
	int* array = create_array(size);
	print_array(array, size);

    node* root = create_tree(array, size);
    print_preorder(root);
	printf("\n");

	root = search(root, 4);
	root = insert(root, 20);
	root = delete(root, 4);

	print_preorder(root);

    return 0;
}
