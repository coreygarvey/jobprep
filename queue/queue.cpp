/* Corey Garvey - July 7
 * Queue Implementation */

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

// First in first out
class Queue{
    Node* front;
    Node* back;
    public:
    Queue(){
        front = nullptr;
        back = nullptr;
    }
    void push(int val);
    Node* pop();
    void print();
    void destroy();
};

void Queue::push(int val){
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;
    if(front == nullptr){
        front = newNode;
        back = newNode;
    } else{
        back->next  = newNode;
        back = newNode;
    }
    return;
}

Node* Queue::pop(){
    Node* tmp;
    tmp = front;
    front = front->next;
    return tmp;
}

void Queue::print(){
    Node* pointer;
    pointer = front;
    if(pointer == nullptr){
        cout << "Empty queue!" << endl;
        return;
    }
    while(pointer != nullptr){
        cout << pointer->value << "-";
        pointer = pointer->next;
    }
    cout << "NULL" << endl;
    return;
}

void Queue::destroy(){
    Node* toDie;
    toDie = front;
    if(toDie == nullptr){
        cout << "Empty queue!" << endl;
        return;
    }
    while(toDie != nullptr){
        front = front->next;
        delete toDie;
        toDie = front;
    }
    cout << "Destroyed!" << endl;
}

int main(int argc, char** argv){
    Queue *myqueue = new Queue();
    myqueue->push(12);
    myqueue->push(13);
    myqueue->push(14);
    myqueue->pop();
    myqueue->push(15);
    myqueue->print();
    myqueue->destroy();
    myqueue->print();
    myqueue->destroy();

    return 0;
}

