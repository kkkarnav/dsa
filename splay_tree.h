#ifndef SPLAY_TREE_H_
#define SPLAY_TREE_H_

struct tree_node_type {
    int value;
    struct tree_node_type* left;
    struct tree_node_type* right;
	struct tree_node_type* parent;
	int solid;
};

typedef struct tree_node_type node;


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

#endif
