/* Corey Garvey - July 13th
 * Nth to last element in linked list */
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* nthToLast(Node* head, int n){
    Node* current = head;
    Node* runner = head;
    for(int i=0; i<=n; i++){
        if(current==nullptr){
            cout << "sorry, can't happen" << endl;
            return nullptr;
        }
        current = current->next;
    }
    while(current != nullptr){
        current = current->next;
        runner = runner->next;
    }
    return runner;
}

int main(int argc, char **argv){
    Node *first = new Node();
    first->data = 1;
    first->next = nullptr;
    Node *second = new Node();
    second->data = 2;
    second->next = nullptr;
    first->next = second;
    Node *third = new Node();
    third->data = 3;
    third->next = nullptr;
    second->next = third;
    Node *fourth = new Node();
    fourth->data = 4;
    fourth->next = nullptr;
    third->next = fourth;
    Node *fifth = new Node();
    fifth->data = 5;
    fifth->next = nullptr;
    fourth->next = fifth;
    Node *sixth = new Node();
    sixth->data = 6;
    sixth->next = nullptr;
    fifth->next = sixth;
    Node *seventh = new Node();
    seventh->data = 7;
    seventh->next = nullptr;
    sixth->next = seventh;
    
    cout << first->data << endl;
    cout << first->next->data << endl;
    cout << first->next->next->data << endl;
    
    Node* thirdLast = nthToLast(first, 2);
    cout << thirdLast->data << endl;
    return 0;
}
