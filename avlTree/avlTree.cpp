/* Corey Garvey - Jan 31 2018
*	AVL Trees */
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
using std::queue;


struct Node{
	int key;
	Node *left, *right;
	int height;
};

// Utility function for max of two integers
int max(int a, int b){
	return (a > b)? a : b;
}

// Utility function for getting height of tree
int height(Node *n){
	if(n == nullptr){
		return 0;
	}
	return n->height;
}

// Helper function to create new node
Node* newNode(int key){
	Node* node = new Node();
	
	node->key = key;
	node->left = nullptr;
	node->right = nullptr;
	node->height = 1;
	return node;
}

// Utility function to right rotate subtree rooted w/ x
Node* leftRotate(Node* x){
	Node* y = x->right;
	Node* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// return new root
	return y;
}

// Utility function to left rotate subtree rooted w/ y
Node* rightRotate(Node* y){
	Node* x = y->left;
	Node* T = x->right;

	// Perform rotation
	x->right = y;
	y->left = T;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;

}

// Get balance factor of node
int getBalance(Node* node){
	if(node == nullptr){
		return 0;
	}
	return height(node->left) - height(node->right);
}

// Insert new node with key in tree rooted at node
Node* insert(Node* node, int key){
	// Recursively insert node
	if(node == nullptr){
		return(newNode(key));
	}
	if(key < node->key){
		node->left = insert(node->left, key);
	}
	else if(key > node->key){
		node->right = insert(node->right, key);
	}
	else{
		return node;
	}

	// Update height of this ancestor node
	node->height = 1 + max(height(node->left),
							height(node->right));

	// Get balance factor of this ancestor node
	int balance = getBalance(node);

	// If this node becomes unbalanced, there are 4 cases

	// Left left
	if(balance > 1 && key < node->left->key){
		return rightRotate(node);
	}

	// Left right
	if(balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right right
	if(balance < -1 && key > node->right->key){
		return leftRotate(node);
	}

	// Right left
	if(balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	// Return node
	return node;
}

/* Give non-empty binary search tree, return node with minimum
*	key value found in the tree. */
Node* minValueNode(Node* node){
	Node* current = node;

	// Loop down to find left most leaf
	while(current->left != nullptr){
		current = current->left;
	}
	return current;
}

// Recursive delete fuction
Node* deleteNode(Node* root, int key){
	// Recursively search for node and delete
	if(root == nullptr){
		return root;
	}

	// If key is smaller than root, look left
	if(key < root->key){
		root->left = deleteNode(root->left, key);
	}
	else if(key > root->key){
		root->right = deleteNode(root->right, key);
	}

	// If key == root->key, found the node!
	else{
		// No child or one child
		if( (root->left == nullptr) || (root->right == nullptr)){
			Node* tmp = root->left ? root->left : root->right;

			// No child
			if(tmp == nullptr){
				tmp = root;
				root = nullptr;
			}
			// One child
			else{
				*root = *tmp; // Copy contents
			}
			delete tmp;
		}
		else{
			// Get in order successor of root
			Node* tmp = minValueNode(root->right);

			// Copy in order successor data to this node
			root->key = tmp->key;

			// Delete in order successor
			root->right = deleteNode(root->right, tmp->key);
		}
	}
	// If tree had only one node, return
	if(root == nullptr){
		return root;
	}
	// Update height of current
	root->height = max(height(root->left), height(root->right)) + 1;

	// Get balance factor of node
	int balance = getBalance(root);

	// Left left
	if(balance > 1 && getBalance(root->left) >= 0) {
		return rightRotate(root);
	}
	// Left right
	if(balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// Right right
	if(balance < -1 && getBalance(root->right) <= 0) {
		return leftRotate(root);
	}
	// Right left
	if(balance < -1 && getBalance(root->left) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}


// Utility to print preorder traversal
void preOrder(Node* root){
	if(root != nullptr){
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){
	Node* root = nullptr;

	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);
	
	cout << "Preorder traversal of AVL tree: " << endl;
	preOrder(root);

	root = deleteNode(root, 10);
	cout << "Preorder traversal of AVL tree after deletion of 10: " << endl;
	preOrder(root);


	return 0;
}

