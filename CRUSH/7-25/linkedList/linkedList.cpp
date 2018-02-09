/* Corey Garvey - July 25
 * Linked List */
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* newNode(int val){
    Node* tmp = new Node;
    tmp->data = val;
    tmp->next = nullptr;
    return tmp;
}

class LinkedList{
    Node* head;
    public:
        LinkedList(int val){
            Node* firstNode = newNode(val);
            head = firstNode;
        }

        void appendToTail(int val){
            Node* tmp = newNode(val);
            Node* runner = head;
            while(runner->next!=nullptr){
                runner = runner->next;
            }
            runner->next = tmp;
        }
        
        void appendToHead(int val){
            Node* tmp = newNode(val);
            tmp->next = head;
            head = tmp;
        }
        
        void removeNode(int val){
            Node* runner = head;
            while(runner->next->data != val && runner->next != nullptr){
                runner = runner->next;
            }
            if(runner->next->data == val){
                runner->next = runner->next->next;
            } else {
                cout << "Node not present" << endl;
            }
            return;
        }
        void printLL(){
            if(head==nullptr){
                cout << "Empty Linked List" << endl;
                return;
            } else {
                Node* runner = head;
                while(runner->next != nullptr){
                    cout << runner->data << "-";
                    runner = runner->next;
                }
                cout << runner->data << endl;
            }
            return;
        }
};

int main(int argc, char** argv){
    LinkedList* myLL = new LinkedList(1);
    myLL->appendToTail(2);
    myLL->appendToTail(3);
    myLL->appendToTail(4);
    myLL->appendToHead(5);
    myLL->removeNode(3);
    myLL->printLL();
    return 0;
}
