/* Corey Garvey - July 20
 * Stack */
#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* newNode(int val){
    node* thisNode = new node;
    thisNode->data = val;
    thisNode->next = nullptr;
    return thisNode;
}

class Stack{
    node* top;
    public:
        
        Stack(){
            top = nullptr;
        }
        
        Stack(int val){
            node* firstNode = newNode(val);
            top = firstNode;
        }
        
        void push(int val){
            node* thisNode = newNode(val);
            thisNode->next = top;
            top = thisNode;
            return;
        }
        
        int pop(){
            node* returnNode = top;
            int returnVal = returnNode->data;
            top = top->next;
            delete returnNode;
            return returnVal;
        }

        void printStack(){
            cout << "Stack: " << endl;
            node* thisNode = top;
            if(thisNode == nullptr){
                cout << "Empty!" << endl;
            }
            while(thisNode->next != nullptr){
                cout << thisNode->data << "-";
                thisNode = thisNode->next;
            }
            cout << thisNode->data << endl;
        }

        ~Stack(){
            node* thisNode = top;
            while(thisNode != nullptr){
                node* next = thisNode->next;
                delete thisNode;
                thisNode = next;
            }
        }
};

int main(int argc, char** argv){
    Stack myStack = Stack(1);
    Stack *stackAddr = &myStack;
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    stackAddr->push(5);
    stackAddr->push(6);
    myStack.pop();
    myStack.printStack();
    Stack *stk = new Stack(11);
    stk->push(12);
    stk->push(13);
    stk->push(14);
    stk->pop();
    stk->printStack();
    return 0;

} 
