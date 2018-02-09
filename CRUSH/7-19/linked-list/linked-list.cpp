/* Corey Garvey - July 19
 * Linked List */
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    public:
        Node* head;
        LinkedList(int val){
            Node* newNode = new Node;
            newNode->data = val;
            newNode->next = nullptr;
            head = newNode;
        }
        void appendToTail(int val){
            Node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            Node* tmp = new Node;
            tmp->data = val;
            tmp->next = nullptr;
            current->next = tmp;
        }
        void appendToHead(int val){
            Node* tmp = new Node;
            tmp->data = val;
            tmp->next = head;
            head = tmp;
        }
        Node* removeNode(int val){
            Node* current = head;
            if(current->data == val){
                head = current->next;
                delete current;
            }
            while(current->next != nullptr){
                if(current->next->data == val){
                    Node* tmp = current->next;
                    current->next = current->next->next;
                    cout << "found it" << endl;
                    return tmp;
                }
                current = current->next;
            }
            cout << "Sorry, not in list" << endl;
            return nullptr;
        }
};
int main(int argc, char** argv){
    LinkedList myList = LinkedList(1);
    myList.appendToTail(2);
    myList.appendToTail(3);
    myList.appendToHead(4);
    myList.removeNode(1);
    Node* head = myList.head;
    cout << head->data << endl;
    cout << head->next->data << endl;
    cout << head->next->next->data << endl;
    return 0; 
}
