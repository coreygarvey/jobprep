/* Corey Garvey - July 7
 * Linked Lists */
#include <iostream>
#include <stddef.h>
using namespace std;


class Node{
    public:
        Node *next;
        int data;
         
        Node(int inputData){
            this->data = inputData;
            this->next = NULL;
        }
        void appendToTail(int data){
            Node *newNode = new Node(data);
            Node *thisNode = this;
            if(thisNode != NULL){
                while(thisNode->next != NULL){
                    thisNode = thisNode->next;
                }
                thisNode->next = newNode;
                return;
            }
        }
};

class LinkedList{
    public:
        Node *head;
        LinkedList(Node *node){
            head = node;
        }
        void appendToTail(int data){
            Node *newNode = new Node(data);
            Node *thisNode = head;
            if(thisNode != NULL){
                while(thisNode->next != NULL){
                    thisNode = thisNode->next;
                }
                thisNode->next = newNode;
                return;
            }
        }
        void deleteNode(int data){
            Node *thisNode = head;
            if(thisNode->data == data){
                head = thisNode->next;
                return;
            }
            while(thisNode->next != NULL){
                if(thisNode->next->data == data){
                    thisNode->next = thisNode->next->next;
                    return;
                }
                thisNode=thisNode->next;
            }
            return;
        }
};
Node* deleteNode(Node *head, int data){
    Node *thisNode = head;
    if(thisNode->data == data){
        return head->next;
    }
    while(thisNode->next != NULL){
        if(thisNode->next->data == data){
            thisNode->next = thisNode->next->next;
            return head;
        }
        thisNode=thisNode->next;
    }
    return head;
};
int main(){
    Node *nodeLL = new Node(12);
    Node *classNode = new Node(12);
    LinkedList *classLL = new LinkedList(classNode);
    nodeLL->appendToTail(13);
    nodeLL->appendToTail(14);

    classLL->appendToTail(13);
    classLL->appendToTail(14);
    cout << "nodeLL: " << endl;
    cout << nodeLL->data << endl;
    cout << nodeLL->next->data << endl;
    cout << nodeLL->next->next->data << endl;
    deleteNode(nodeLL, 13);
    cout << "deleted nodeLL 13" << endl;
    cout << nodeLL->data << endl;
    cout << nodeLL->next->data << endl;

    cout << "classLL: " << endl;
    cout << classLL->head->data << endl;
    cout << classLL->head->next->data << endl;
    cout << classLL->head->next->next->data << endl;
    
    classLL->deleteNode(13);
    cout << "deleted classLL 13" << endl;
    cout << classLL->head->data << endl;
    cout << classLL->head->next->data << endl;

    return 0;
}
