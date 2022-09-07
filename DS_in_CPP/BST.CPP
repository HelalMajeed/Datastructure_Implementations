#include <iostream>

using namespace std;

struct node {
		int data;
		node *left;
		node *right;
};

node *root = NULL;

node *create_node(int value) {
	node *root = new node;
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
	node *ptr = root;
	node *new_node = new node;
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

void print_inorder(node *ptr) {
	if (ptr == NULL) 
		return;
	print_inorder(ptr->left);
	cout << ptr->data << " ";
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
