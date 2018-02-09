/* Corey Garvey - January 26 2018
 * Stack, Queue, Graph - BFS, DFS */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct node{
	int value;
	node* next;
};

node* newNode(int val){
	node* thisNode = new node;
	thisNode->value = val;
	thisNode->next = nullptr;
	return thisNode;
}

//
class Stack{
	node* top;
	public:
		Stack(){
			top = nullptr;
		}
		~Stack(){
			node* thisNode = top;
			node* tmp;
			while(thisNode != nullptr){
				tmp = thisNode->next;
				delete thisNode;
				thisNode = tmp;
			}
		}

		void push(int val){
			node* thisNode = newNode(val);
			thisNode->next = top;
			top = thisNode;
			return;
		}

		int pop(){
			if(top == nullptr){
				cout << "Empty Stack" << endl;
				return -1;
			}
			node* returnNode = top;
			top = top->next;
			int returnValue = returnNode->value;
			delete returnNode;
			return returnValue;
		}

		void printStack(){
			if(top == nullptr){
				cout << "Empty Stack" << endl;
			}
			node* thisNode = top;
			while(thisNode->next != nullptr){
				cout << thisNode->value << "-";
				thisNode = thisNode->next;
			}
			cout << thisNode->value  << endl;
			return;
		}

		bool empty(){
			return top == nullptr;
		}
};

class Queue{
	node* front;
	node* back;
	public:
		Queue(){
			front = nullptr;
			back = nullptr;
		}
		~Queue(){
			node* thisNode = front;
			node* tmp;
			while(thisNode != nullptr){
				tmp = thisNode->next;
				delete thisNode;
				thisNode = tmp;
			}
		}

		void enqueue(int val){
			node* thisNode = newNode(val);
			if(front==nullptr){
				front = thisNode;
				back = thisNode;
				return;
			}
			back->next = thisNode;
			back = thisNode;
			return;
		}
		int dequeue(){
			if(front == nullptr){
				cout << "Empty Queue" << endl;
				return -1;
			}
			node* returnNode  = front;
			front = returnNode->next;
			int returnValue = returnNode->value;
			delete returnNode;
			return returnValue;
		}

		void printQueue(){
			if(front == nullptr){
				cout << "Empty Queue" << endl;
				return;
			}
			node* thisNode = front;
			while(thisNode->next != nullptr){
				cout << thisNode->value << "-";
				thisNode = thisNode->next;
			}
			cout << thisNode->value << endl;
			return;
		}

		bool empty(){
			return front == nullptr;
		}
};


class Graph{
	int** edges;
	int size;
	public:
		Graph(int s){
			if(s < 2) size = 2;
			size = s;
			// Create graph as 2D array representing all edges
			for(int i=0; i<size; i++){
				edges[i] = new int[size];
			}
			for(int i=0; i<size; i++){
				for(int j=0; j<size; j++){
					edges[i][j] = 0;
				}
			}
		}
		~Graph(){
			for(int i=0; i<size; i++){
				delete [] edges[i];
			}
			delete [] edges;
		}

		void addEdge(int u, int v){
			edges[u-1][v-1] = edges[v-1][u-1] = 1;
			return;
		}

		bool hasConnection(int u, int v){
			return edges[u-1][v-1];
		}

		string BFS(int start, int find){
			// Breadth first search
			// Use a Queue - FIFO
			ostringstream oss;
			Queue* q = new Queue();
			bool* visited = new bool[size+1];
			for(int i=0; i<=size; i++){
				visited[i] = false;
			}
			q->enqueue(start);
			visited[start] = true;
			int current;
			while(!q->empty()){
				current = q->dequeue();
				oss << current << " ";
				if(current == find){
					return oss.str();
				}
				for(int i=0; i<size; i++){
					if(hasConnection(current, i)){
						q->enqueue(i);
						visited[i] = true;
					}
				}
			}
			return "No path, sorry";
		}

		string DFS(int start, int find){
			// Depth first search
			// Use a Stack - FILO
			ostringstream oss;
			Stack* stack = new Stack();
			bool* visited = new bool[size+1];
			for(int i=0; i<= size; i++){
				visited[i] = false;
			}

			stack.push(start);
			visited[start] = true;
			int current;
			while(!stack->empty()){
				current = stack.pop();
				oss << current << " ";
				if(current == find){
					return oss.string();
				}
				for(int i=0; i<size; i++){
					if(hasConnection(current, i)){
						stack.push(i);
						
					}
				}
			}



		}
}