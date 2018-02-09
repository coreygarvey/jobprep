/* Corey Garvey - Jan 30 2018
*	Replace Duplicate Nodes */
#include <iostream>
#include <cstring>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void replaceDups(Node* head){
	Node* thisNode = head;
	// N^2 move from 1st to last and check all others for dups
	while(thisNode->next->next != nullptr){
		Node* nextNode = thisNode->next;
		int thisData = thisNode->data;
		int nextData = nextNode->data;
		while(nextNode != nullptr){
			if(thisData == nextData){
				thisNode->next = nextNode->next;
			}
			nextNode = nextNode->next
		}
	}
}

void printList(Node* head){
	Node* thisNode = head;
	while(thisNode->next != nullptr){
		cout << thisNode->data << "-";
		thisNode = thisNode->next;
	}
	cout << thisNode->data << endl;

}

void appendToTail(Node* head, int data){
	Node* thisNode = head;
	while(thisNode->next != nullptr){
		thisNode = thisNode->next;
	}
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;
	thisNode->next = newNode;
}

int main(int argc, char** argv){

	Node* head = new Node();
	head->data = 1;
	head->next = nullptr;
	appendToTail(head, 2);
	appendToTail(head, 3);
	appendToTail(head, 4);
	appendToTail(head, 3);
	appendToTail(head, 5);

	printList(head);

	return 0;
}