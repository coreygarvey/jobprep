/* Corey Garvey - Feb 1 2018
*	Splay Trees */
#include <iostream>

using namespace std;

struct Node{
	int data;
	Node *left, *right, *parent;

	// Constructor
	Node(int data){
		this->data = data;
		this->left = this->right = nullptr;
		this->parent = nullptr;
	}
};

// Utility function to rotate right around root y w/ left being x
Node* rightRotate(Node *y){
	Node *x = y->left;
	Node *T = x->right;
	y->left = T;
	x->right = y;
	return x;
}

// Utility function to rotate left around root x w/ right being y
Node* leftRotate(Node *x){
	Node *y = x->right;
	Node *T = y->left;
	x->right = T;
	y->left = x;
	return y;
}

Node* splay(Node *root, int val){
	// Base case: root is nullptr or val is at root;
	if(root == nullptr || root->data == val){
		return root;
	}

	// Val in LEFT subtree
	if(val < root->data){
		// Val not in tree
		if(root->left == nullptr){
			return root;
		}

		// Left Left
		if(val < root->left->data){
			// Recursively search for val
			root->left->left = splay(root->left->left, val);

			// First rotation for the root
			root = rightRotate(root);
		}
		// Left Right
		else if(val > root->left->data){
			// Recursively search for val
			root->left->right = splay(root->left->right, val);

			// Do first rotation for root->left
			if(root->left->right != nullptr){
				root->left = leftRotate(root->left);
			}
		}

		// Second rotation for the root
		root = (root->left == nullptr) ? root : rightRotate(root);
		return root;
	}

	// Val in RIGHT subtree
	//else if(val > root->data){
	else {		
		// Not in tree
		if(root->right == nullptr){
			return root;
		}

		// Right Right
		if(val > root->right->data){
			// Recursively search for val
			root->right->right = splay(root->right->right, val);
			root = leftRotate(root);
		}
		// Right Left
		else if(val < root->right->data){
			// Recursively search for val
			root->right->left = splay(root->right->left, val);
			root->right = rightRotate(root->right);
		}
		// Second rotation for root
		root = (root->right == nullptr) ? root : leftRotate(root);
		return root;
	}
}

Node* search(Node *root, int key){
	return splay(root, key);
}

void inorder(Node* node){
	if(node == nullptr){
		return;
	}
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

void preorder(Node* node){
	if(node == nullptr){
		return;
	}
	cout << node->data << " ";
	inorder(node->left);
	inorder(node->right);
}


int main(){

	// Build Tree
	Node* root = new Node(100);
	// Insert multiple objects
	root->left = new Node(50);
	root->right = new Node(200);
	root->left->left = new Node(40);
	root->left->left->left = new Node(30);
	root->left->left->left->left = new Node(20);
	cout << "Preorder traversal after building" << endl;
	preorder(root);
	cout << endl;
	// Search for various values (splaying return value)
	root = search(root, 20);
	// Print inorder traversal
	cout << "Preorder traversal of splay tree after search for 20" << endl;
	preorder(root);
	cout << endl;

	return 0;
}