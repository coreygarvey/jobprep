/* Corey Garvey - July 12
 * Remove Dupes from Linked List */

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

void removeDupes(Node *head){
    if(head == nullptr) return;
    Node *previous = head;
    Node *current = previous->next;
    while(current != nullptr){
        Node *runner = head;
        while(runner !=current){
            if(current->data == runner->data){
                previous->next = current->next;
                current = current->next;
                // Cannot be 2 dupes for 1 runner
                //  Would have been removed already
                break;
            } 
            runner = runner->next;
        }
        if(runner == current){
            previous = current;
            current = current->next;
        }
    }
}



int main(int argc, char **argv){
    Node *linkedList = new Node();
    linkedList->data = 4;
    linkedList->next = nullptr;
    Node *node2 = new Node();
    node2->data = 2;
    node2->next = nullptr;
    linkedList->next = node2;
    Node *node3 = new Node();
    node3->data = 4;
    node3->next = nullptr;
    node2->next = node3;
    Node *node4 = new Node();
    node4->data = 3;
    node4->next = nullptr;
    node3->next = node4;
    cout << linkedList->data << endl;
    cout << linkedList->next->data << endl;
    cout << linkedList->next->next->data << endl;
    cout << linkedList->next->next->next->data << endl;
    removeDupes(linkedList);
    cout << linkedList->data << endl;
    cout << linkedList->next->data << endl;
    cout << linkedList->next->next->data << endl;

    return 0;
}
