/* Corey Garvey - Feb 1 2018
*	nth to last element in linked list */

#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;

	// Constructor
	Node(int data){
		this->data = data;
		next = nullptr;
	}
};

class LinkedList{
public:
	Node* root;

	// Constructor
	LinkedList(){
		this->root = nullptr;
	}
	
	void insert(int data){
		Node* newNode = new Node(data);
		Node* current = root;
		if(current==nullptr){
			root = newNode;
			return;
		}
		while(current->next != nullptr){
			current = current->next;
		}
		current->next = newNode;
		return;
	}

	Node* findNthLastElement(int n){
		Node *runner, *trailer;
		runner = trailer = this->root;
		for(int i=0; i<n-1; i++){
			if(runner == nullptr){
				cout << "Not enough nodes" << endl;
				return nullptr;
			}
			runner = runner->next;
		}
		while(runner->next != nullptr){
			runner = runner->next;
			trailer = trailer->next;
		}
		return trailer;
	}

	Node* findNthLastElementRecursion(Node *node, int n){
		static int i = 0;
		Node* result = nullptr;
		if(node != nullptr){
			result = findNthLastElementRecursion(node->next, n);	
			

			if(result != nullptr){
				cout << i << " : " << result->data << endl;
			}

			// i is iterated up to list length, only storing result at n
			if(++i == n){
				result = node;
			}
			cout << "i: " << i  << endl;
		}
		return result;
	}
};

int main(){
	LinkedList* ll = new LinkedList();
	ll->insert(1);
	ll->insert(2);
	ll->insert(3);
	ll->insert(4);
	ll->insert(5);
	ll->insert(6);

	Node* thirdLast = ll->findNthLastElement(3);

	cout << "3rd last element: " << thirdLast->data << endl;

	Node* thidLast = ll->findNthLastElementRecursion(ll->root, 3);
	cout << "3rd last element (recursive): " << thirdLast->data << endl;
	return 0;
}