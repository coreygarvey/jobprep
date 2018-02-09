/* Corey Garvey - July 14
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
    LinkedList(int value){
        head = new Node;
        head->data = value;
        head->next = nullptr;
    }
    void appendToTail(int value){
        Node* current = head;
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
        return;
    }
    void deleteNode(int value){
        Node* current = head;
        Node* currentStore;
        if(current->data == value){
            cout << "Deleting head" << endl;
            currentStore = head;
            head = current->next;
            delete currentStore;
            return;
        }
        while(current->next->data != value){
            if(current->next == nullptr){
                cout << "Sorry, not found" << endl;
                return;
            }
            current = current->next;
        }
        currentStore = current->next;
        current->next = current->next->next;
        delete currentStore;
        return;
    }
    void appendToHead(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        return;
    }
};

Node* appendToTail(Node* root, int value){
    Node* current = root;
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    while(current->next != nullptr){
       current = current->next;
    }
    current->next = newNode;
    return root;
}

Node* appendToHead(Node* root, int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = root;
    return newNode;
}

Node* removeNode(Node* root, int value){
    Node* current = root;
    if(current->data == value){
        cout << "Looks like it's the head" << endl;
        return current->next;
    }
    while(current->next->data != value){
        if(current->next->next == nullptr){
            cout << "Sorry, node's not in here" << endl;
            return root;
        }
        current = current->next;
    }
    Node* nextNode = current->next;
    current->next = current->next->next;
    delete nextNode;
    return root;
}

int main(int argc, char** argv){
    Node* rootNode = new Node;
    rootNode->data = 1;
    rootNode->next = nullptr;
    rootNode = appendToTail(rootNode, 2);
    rootNode = appendToTail(rootNode, 3);
    rootNode = appendToTail(rootNode, 4);
    rootNode = appendToTail(rootNode, 5);
    rootNode = appendToTail(rootNode, 6);
    rootNode = appendToHead(rootNode, 7);
    rootNode = removeNode(rootNode,4);

    cout << rootNode->data << endl;
    cout << rootNode->next->data << endl;
    cout << rootNode->next->next->data << endl;
    cout << rootNode->next->next->next->data << endl;
    cout << rootNode->next->next->next->next->data << endl;

    LinkedList myLL = LinkedList(1);
    myLL.appendToTail(2);
    myLL.appendToTail(3);
    myLL.appendToTail(4);
    myLL.appendToTail(5);
    myLL.appendToTail(6);
    myLL.appendToHead(7);
    myLL.deleteNode(7);
    cout << "Class implementation:" << endl;
    cout << myLL.head->data << endl;
    cout << myLL.head->next->data << endl;
    cout << myLL.head->next->next->data << endl;
    cout << myLL.head->next->next->next->data << endl;
    cout << myLL.head->next->next->next->next->data << endl;
    return 0;
}
