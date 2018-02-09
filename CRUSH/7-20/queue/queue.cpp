/* Corey Garvey - July 20
 * Queue */
#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class queue{
    node *front;
    node *back;
    public:
        queue(int val){
            node* thisNode = new node;
            thisNode->data = val;
            thisNode->next = nullptr;
            front = thisNode;
            back = thisNode;
        }
        void enqueue(int val){
            node* newNode = new node;
            newNode->data = val;
            newNode->next = nullptr;
            if(front == nullptr){
                front = newNode;
            }
            back->next = newNode;
            back = newNode;
            return;
        }
        node* dequeue(){
            if(front == nullptr){
                cout << "sorry, empty" << endl;
                return nullptr;
            }
            node* released = front;
            front = front->next;
            if(front == nullptr){
                back = nullptr;
            }
            return released;
        }
        void printQueue(){
            node* thisNode = front;
            if(thisNode==nullptr){
                cout << "Empty queue" << endl;
            }
            while(thisNode->next != nullptr){
                cout << thisNode->data << "-";
                thisNode = thisNode->next;
            }
            cout << thisNode->data << endl;
            return;
        }
        ~queue(){
            node* thisNode = front;
            while(thisNode != nullptr){
                node* next = thisNode->next;
                delete thisNode;
                thisNode = next;
            }
        }
};

int main(int argc, char** argv){
    queue myQueue = queue(1);
    queue *queueAddr = &myQueue;
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    queueAddr->enqueue(5);
    queueAddr->enqueue(6);
    myQueue.dequeue();
    myQueue.printQueue();
    return 0;
}; 
