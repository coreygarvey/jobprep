/* Corey Garvey - Feb 1 2018
*	Trie	*/

#include <iostream>

using namespace std;

const int ALPHABET = 26;

struct Node{
	// Array of nodes for each possible succeeding letter
	Node *nextLetters[ALPHABET];

	bool endOfWord;
};

Node* newNode(){
	Node *node = new Node;
	node->endOfWord = false;

	for(int i=0; i<ALPHABET; i++){
		node->nextLetters[i] = nullptr;
	}

	return node;
}

void insert(Node *root, string word){

	Node *crawlNode = root;
	for(int i=0; i<word.length(); i++){
		int index = word[i] - 'a';
		if(!crawlNode->nextLetters[index]){
			crawlNode->nextLetters[index] = newNode();
		}
		crawlNode = crawlNode->nextLetters[index];
	}
	crawlNode->endOfWord = true;
}

bool search(Node *root, string word){
	Node *crawlNode = root;
	for(int i=0; i<word.length(); i++){
		int index = word[i] - 'a';
		if(!crawlNode->nextLetters[index]){
			return false;
		}
		crawlNode = crawlNode->nextLetters[index];
	}
	return (crawlNode != nullptr && crawlNode->endOfWord);
}


int main(int argc, char** argv){
	string all[] = {"an", "answer", "any", "the", "their", "this", "tease", "test"};

	int n = sizeof(all)/sizeof(all[0]);
	// Create Root
	Node *root = newNode();
	// Insert all strings into root
	for(int i=0; i<n; i++){
		insert(root, all[i]);
	}
	// Search for strings
	cout << "the: " << search(root, "the") << endl;
	cout << "these: " << search(root, "these") << endl;
	cout << "tea: " << search(root, "tea") << endl;
	cout << "test: " << search(root, "test") << endl;

	return 0;
}