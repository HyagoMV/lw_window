#pragma once
#ifndef IOSTREAM_H
#define IOSTREAM_H

#include <iostream>

#endif // IOSTREAM_H

#define show(value) std::cout << value << " ";
#define newLine std::cout << std::endl;

struct Node {
	int data = 0;
	struct Node* left = nullptr;
	struct Node* right = nullptr;
	
	
	Node(int date) {
		this->data = date;
	}
};

void showInorder(Node* node) {
	// Null check
	if (node == nullptr) return;
	
	showInorder(node->left);
	show(node->data);
	showInorder(node->right);
}

void showPreOrder(Node* node) {
	// Null check
	if (node == nullptr) return;
	
	show(node->data);
	showPreOrder(node->left);
	showPreOrder(node->right);
}

void showPostOrder(Node* node) {
	// Null check
	if (node == nullptr) return;

	showPostOrder(node->left);
	showPostOrder(node->right);
	show(node->data);
}

int main2() {
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	showInorder(root);
	newLine;
	showPreOrder(root);
	newLine;
	showPostOrder(root);
	return 0;
}