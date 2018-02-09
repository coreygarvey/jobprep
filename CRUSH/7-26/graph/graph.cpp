/* Corey Garvey - July 26
 * Graphs */

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* newNode(int value){
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = nullptr;
    return tmp;
}

// Stack
class Stack{
    public:
        Node* top;
        Stack(int val){
            Node* firstNode = newNode(val);
            top = firstNode;
        }
        void insert(int val){
            Node* thisNode = newNode(val);
            thisNode->next = top;
            top = thisNode;
            return;
        }
        int remove(){
            if(top == nullptr){
                cout << "Sorry, empty stack" << endl;
            }
            Node* tmp = top;
            top = top->next;
            int returnVal = tmp->data;
            delete tmp;
            return returnVal;
        }
        void printStack(){
            Node* runner = top;
            if(top == nullptr){
                cout << "Empty Stack" << endl;
            }
            cout << "Printing stack: " << endl;
            while(runner->next != nullptr){
                cout << runner->data << "-";
                runner = runner->next;
            }
            cout << runner->data << endl;
            return;
        }
};

// Queue
class Queue{
    public:
        Node* front;
        Node* back;
        Queue(int val){
            Node* firstNode = newNode(val);
            front = firstNode;
            back = firstNode;
        }
        void insert(int val){
            Node* thisNode = newNode(val);
            if(front==nullptr){
                front = thisNode;
                back = thisNode;
                return;
            }
            back->next = thisNode;
            back = thisNode;
            return;
        }
        int remove(){
            if(front == nullptr){
                cout << "Empty Queue" << endl;
                return -1;
            }
            Node* tmp = front;
            front = front->next;
            int returnVal = tmp->data;
            delete tmp;
            return returnVal;
        }
        void printQueue(){
            if(front==nullptr){
                cout << "Empty Queue" << endl;
                return;
            }
            Node* runner = front;
            while(runner->next != nullptr){
                cout << runner->data << "-";
                runner = runner->next;
            }
            cout << runner->data << endl;
            return;
        }
};

int main(int argc, char** argv){
    Queue* myQueue = new Queue(3);
    myQueue->insert(4);
    myQueue->insert(5);
    myQueue->insert(6);
    myQueue->remove();
    myQueue->printQueue();

    Stack* myStack = new Stack(3);
    myStack->insert(4);
    myStack->insert(5);
    myStack->insert(6);
    myStack->remove();
    myStack->printStack();
    return 0;
}
