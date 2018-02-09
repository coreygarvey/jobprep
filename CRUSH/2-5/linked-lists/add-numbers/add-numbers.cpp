/* Corey Garvey - Feb 5 2018
*	Add Two Linked Numbers */

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	// Constructor
	Node(int val){
		data = val;
		next = nullptr;
	}
};

void addNode(Node *root, int val){

	Node *newNode = new Node(val);
	if(root == nullptr) {
		return;
	}
	Node* current = root;
	while(current->next != nullptr){
		current = current->next;
	}
	current->next = newNode;
	return;
}

void printNumber(Node *root){
	if(root==nullptr){
		cout << "No number here" << endl;
		return;
	}
	Node* current = root;
	string output, currentData; 
	while(current->next != nullptr){
		currentData = to_string(current->data);
		output = currentData + output;
		current = current->next;
	}
	currentData = to_string(current->data);
	output = currentData + output;
	cout << output << endl;
	return;
}

Node* sumNumbers(Node *number1, Node *number2){
	if(number1 == nullptr) return number2;
	if(number2 == nullptr) return number1;

	int sum;
	int remain = 0;
	int value1, value2;
	Node* current1 = number1;
	Node* current2 = number2;
	Node* returnNum = nullptr;
	while(current1 != nullptr || current2 != nullptr){
		if(current1 != nullptr){
			value1 = current1->data;
			current1 = current1->next;
		} else{
			value1 = 0;
		}
		if(current2 != nullptr){
			value2 = current2->data;
			current2 = current2->next;
		} else{
			value2 = 0;
		}
		sum = value1 + value2 + remain;
		if(sum>10) remain = 1;
		else remain = 0;
		if(remain>0) sum = sum - 10;
		if(returnNum==nullptr) returnNum = new Node(sum);
		else addNode(returnNum, sum);
	}
	if(remain>0) addNode(returnNum, remain);
	return returnNum;
}

int main(){
	
	Node* number1 = new Node(3);
	addNode(number1, 4);
	addNode(number1, 8);

	Node* number2 = new Node(9);
	addNode(number2, 3);
	addNode(number2, 9);

	printNumber(number1);
	printNumber(number2);

	Node* sum = sumNumbers(number1, number2);

	printNumber(number1);
	printNumber(number2);
	
	printNumber(sum);

	return 0;
}