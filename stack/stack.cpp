/* Corey Garvey - July 7
 * Stack Implementation */

#include <iostream>
using namespace std;

// Create Node stucture
struct Node {
    int value;
    struct Node *next;
};

/* First in last out */
// Create Stack class
class Stack {
    Node *top;
    
    public:
    Stack(){
        top = nullptr;
    }

    void push(int val);
    Node* pop();
    void print();
    void destroy();
};

// Stack methods
//  push
void Stack::push(int val) {
    Node *newNode = new Node;
    newNode->value = val;
    if (top == nullptr){
        top = newNode;
        newNode->next = nullptr;
        return;
    }
    newNode->next = top;
    top = newNode;
    return;
}

//  pop
Node* Stack::pop(){
    Node *tmp;
    if(top == nullptr){
        cout << "Empty stack!" << endl;
        return nullptr;
    }
    tmp = top;
    top = top->next;
    return tmp;
}

// print
void Stack::print(){
    Node *thisNode;
    thisNode = top;
    while(thisNode != nullptr){
        cout << thisNode->value << "-";
        thisNode = thisNode->next;
    }
    cout << "NULL" << endl;
}

// destroy
void Stack::destroy(){
    Node *toDie;
    if(top == nullptr){
        cout << "already empty" << endl;
        return;
    }
    while(top != nullptr){
        toDie = top;
        top = top->next;
        delete toDie;
    }
    cout << "Destroyed" << endl;
}

int main(int argc, char **argv){
    Stack *mystack = new Stack();
    mystack->push(12);
    mystack->push(13);
    mystack->push(14);
    mystack->pop();
    mystack->push(15);
    mystack->print();
    mystack->destroy();
    mystack->print();
    mystack->destroy();
    return 0;
}
