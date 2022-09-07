#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
		int data;
		struct node *left;
		struct node *right;
} node;

struct node *root = NULL;

struct node *create_node(int value) {
	struct node *root = (struct node*)malloc(sizeof(struct node));
	root->data = value;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void insert(int value) {
	if (root == NULL) {
		root = create_node(value);
		return;
	}
	struct node *ptr = root;
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;
	while (true) {
		if (value <= ptr->data && ptr->left != NULL) {
			ptr = ptr->left;
		}	
		if (value <= ptr->data && ptr->left == NULL) {
			ptr->left = new_node;
			break;
		}	
		if (value >  ptr->data && ptr->right != NULL) {
			ptr = ptr->right;
		}	
		if (value >  ptr->data && ptr->right == NULL) {
			ptr->right = new_node;
			break;
		}	
	}
}

void print_inorder(struct node *ptr) {
	if (ptr == NULL) 
		return;
	print_inorder(ptr->left);
	printf("%d ", ptr->data);
	print_inorder(ptr->right);
}

int main() {
	root = create_node(4);
	insert(1);
	insert(0);
	insert(2);
	insert(6);
	insert(7);
	insert(5);
	print_inorder(root);
	return 0;
}
