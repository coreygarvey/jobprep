/* Corey Garvey - Jan 31 2018
*	Red Black Tree */

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
using std::queue;

enum Color {RED, BLACK};

struct Node{
	int data;
	bool color;
	Node *left, *right, *parent;

	// Constructor
	Node(int data){
		this->data = data;
		left = right = parent = nullptr;
	}
};

// Class representing RB Tree
class RBTree{
private:
	Node *root;
protected:
	void rotateLeft(Node *&root, Node *&pt);
	void rotateRight(Node *&root, Node *&pt);
	void fixViolation(Node *&root, Node *&pt);
public:
	// Constructor
	RBTree() { root = nullptr; }
	void insert(const int &val);
	void inorder();
	void levelOrder();
};

// Recursive function for in order traversal (DFS)
void inorderHelper(Node *root){
	if (root == nullptr) return;
	inorderHelper(root->left);
	cout << root->data << " ";
	inorderHelper(root->right);
}

// Utility function to do level order traversal
void levelOrderHelper(Node *root){
	if(root == nullptr) return;

	queue<Node *> q;
	q.push(root);

	while(!q.empty()){
		Node *tmp = q.front();
		cout << tmp->data << " ";
		q.pop();

		if(tmp->left != nullptr){
			q.push(tmp->left);
		}
		if(tmp->right != nullptr){
			q.push(tmp->right);
		}
			
	}
	cout << endl;
}

/* Utility function to insert new node with given key in BST */
Node* BSTInsert(Node *root, Node *pt){
	/* If tree empty, return new node */
	if(root == nullptr){
		return pt;
	}

	/* Recur down tree */
	if(pt->data < root->data){
		root->left = BSTInsert(root->left, pt);
		root->left->parent = root;
	}
	else if(pt->data > root->data){
		root->right = BSTInsert(root->right, pt);
		root->right->parent = root;
	}

	/* Return the root node to the caller */
	return root;
}

/* Rotate right */
void RBTree::rotateRight(Node *&root, Node *&pt){
	Node *pt_left = pt->left;
	pt->left = pt_left->right;

	if(pt->left != nullptr){
		pt->left->parent = pt;
	}

	pt_left->parent = pt->parent;

	if(pt->parent == nullptr){
		root = pt_left;
	}
	else if(pt == pt->parent->left){
		pt->parent->left = pt_left;
	}
	else{
		pt->parent->right = pt_left;
	}
	pt_left->right = pt;
	pt->parent = pt_left;
}

/* Rotate left */
void RBTree::rotateLeft(Node *&root, Node *&pt){
	Node *pt_right = pt->right;
	pt->right = pt_right->left;

	if(pt->right != nullptr){
		pt->right->parent = pt;
	}

	pt_right->parent = pt->parent;
	if(pt->parent == nullptr){
		root = pt_right;
	}
	else if(pt == pt->parent->right){
		pt->parent->right = pt_right;
	}
	else{
		pt->parent->left = pt_right;
	}
	pt_right->left = pt;
	pt->parent = pt_right;
}

// Fixes violation caused by insertion
void RBTree::fixViolation(Node *&root, Node *&pt){

	Node *parent_pt = nullptr;
	Node *grandparent_pt = nullptr;

	while((pt != root) && (pt->color != BLACK) &&
			(pt->parent->color == RED)) {

		parent_pt = pt->parent;
		grandparent_pt = pt->parent->parent;

		/* Case A
			Parent of pt is left child of grandparent */
		if(parent_pt == grandparent_pt->left) {
			Node *uncle_pt = grandparent_pt->right;
		
			/* Case 1
				Uncle of pt is also RED
				Only recoloring needed */
			if (uncle_pt != nullptr && uncle_pt->color == RED){
				grandparent_pt->color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grandparent_pt;
			}
			/* Case 2
				Uncle is black */
			else {
				/* Left right 
					pt is right child of its parent
					Left-rotation required */
				if(pt==parent_pt->right){
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}
				/* Left left
					Pt is left child of its parent
					Right rotation required */
				rotateRight(root, grandparent_pt);
				swap(parent_pt->color, grandparent_pt->color);
				pt = parent_pt;
			}
		}

		/* Case B
			Parent of pt is right child of grandparent */
		else {
			Node *uncle_pt = grandparent_pt->left;

			/* Case 1
				Uncle is also RED
				Only recoloring needed */
			if(uncle_pt != nullptr && uncle_pt->color == RED){
				grandparent_pt->color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grandparent_pt;
			}
			/* Case 2
				Uncle is black */
			else {
				/* Right left
					pt is left child of its parent
					Right-rotation required */
				if(pt == parent_pt->left){
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* Right right
					pt is right child of its parent
					Left-rotation required */
				rotateLeft(root, grandparent_pt);
				swap(parent_pt->color, grandparent_pt->color);
				pt = parent_pt;
			}
		}
	}
	root->color = BLACK;
}

// Inserting new node of given data
void RBTree::insert(const int &data){
	Node *pt = new Node(data);

	// BST insert
	root = BSTInsert(root, pt);

	// Fix violations
	fixViolation(root, pt);
}

// Function to do inorder and level order traversals
void RBTree::inorder() { inorderHelper(root); }
void RBTree::levelOrder() { levelOrderHelper(root); }

// Driver
int main(){
	RBTree tree;

	tree.insert(7);
	tree.insert(6);
	tree.insert(5);
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);

	cout << "In order traversal: " << endl;
	tree.inorder();

	cout << "Level order traversal: " << endl;
	tree.levelOrder();

	return 0;
}




