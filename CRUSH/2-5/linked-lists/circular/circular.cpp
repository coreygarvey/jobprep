/* Corey Garvey - Feb 5 2018
*	Circular - Return node at start of loop */

#include <iostream>
using namespace std;

struct Node{
	char data;
	Node* next;
	Node(char val){
		data = val;
		next = nullptr;
	}
};

Node* returnLoop(Node* root){
	Node* slow = root;
	Node* fast = root;
	while(slow != nullptr && fast != nullptr){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			break;
		}
	}
	slow = root;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return fast;

}

int main(){
	Node* a = new Node('A');
	Node* b = new Node('B');
	Node* c = new Node('C');
	Node* d = new Node('D');
	Node* e = new Node('E');
	Node* f = new Node('F');
	Node* g = new Node('G');
	Node* h = new Node('H');
	Node* i = new Node('I');
	Node* j = new Node('J');

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
	h->next = i;
	i->next = j;
	j->next = d;

	Node *loopStart = returnLoop(a);
	cout << loopStart->data << endl;

	return 0;
}