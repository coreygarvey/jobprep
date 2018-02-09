/* Corey Garvey - Feb 5 2018
*	Delete node in middle */

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	// Declare constructor
	Node(int val);
};

// Constructor
Node::Node(int val){
	this->data = val;
	this->next = nullptr;
}

Node* appendNode(Node *root, int val){
	if(root == nullptr) return nullptr;
	Node* current = root;
	while(current->next != nullptr){
		current = current->next;
	}
	Node* newNode = new Node(val);
	current->next = newNode;
	return newNode;
}

void printLinked(Node* root){
	if(root == nullptr) return;
	Node* current = root;
	while(current->next != nullptr){
		cout << current->data << "-";
		current = current->next;
	}
	cout << current->data << endl;
	return;
}

void deleteNode(Node* toDelete){
	if(toDelete == nullptr) return;
	Node* nextNode = toDelete->next;
	if(nextNode == nullptr){
		delete toDelete;
		return;
	}
	toDelete->next = nextNode->next;
	toDelete->data = nextNode->data;
	delete nextNode;
	return;
}

int main(){
	Node* linked = new Node(1);
	Node* second = appendNode(linked,2);
	Node* third = appendNode(linked,3);
	Node* fourth = appendNode(linked,4);
	Node* fifth = appendNode(linked,5);

	printLinked(linked);

	deleteNode(third);

	printLinked(linked);

	return 0;
}