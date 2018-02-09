/* Corey Garvey - July 20
 * Graphs - BFS and DFS */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// node
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

// Stack
class Stack{
    node* top;
    public:
        Stack(){
            top = nullptr;
        }

        ~Stack(){
            node* thisNode = top;
            while(thisNode != nullptr){
                delete thisNode;
                thisNode = thisNode->next;
            }
        }

        void push(int val){
            node* thisNode = newNode(val);
            thisNode->next = top;
            top = thisNode;
            return;
        }
        
        int pop(){
            if(top == nullptr){
                cout << "Empty stack" << endl;
                return -1;
            }
            node* returnNode = top;
            int returnValue = returnNode->data;
            top = returnNode->next;

            delete returnNode;
            return returnValue;
        }
        
        void printStack(){
            if(top == nullptr){
                cout << "Empty stack" << endl;
                return;
            }
            node* thisNode = top;
            while(thisNode->next != nullptr){
                cout << thisNode->data << "-";
                thisNode = thisNode->next;
            }
            cout << thisNode->data << endl;
            return;
        }
        
        bool empty(){
            return top == nullptr;
        }
};


// Queue
class Queue{
    node* front;
    node* back;
    public:
        Queue(){
            front = nullptr;
            back = nullptr;
        }
        
        ~Queue(){
            node* thisNode = front;
            while(thisNode != nullptr){
                node* next = thisNode->next;
                delete thisNode;
                thisNode = next;
            }
        }
        
        void enqueue(int val){
            node* thisNode = newNode(val);
            if(front==nullptr){
                front = thisNode;
                back = thisNode;
                return;
            }
            back->next = thisNode;
            back = thisNode;
            return;
        }

        int dequeue(){
            if(front==nullptr){
                cout << "Empty Queue" << endl;
                return -1;
            }
            node *returnNode = front;
            int returnVal = returnNode->data;
            front = front->next;
            delete returnNode;
            return returnVal;
        }

        void printQueue(){
            if(front == nullptr){
                cout << "Empty Queue" << endl;
                return;
            }
            node* thisNode = front;
            while(thisNode->next != nullptr){
                cout << thisNode->data << "-";
                thisNode = thisNode->next;
            }
            cout << thisNode->data << endl; 
            return;
        }

        bool empty(){
            return front == nullptr;
        }
};




// Graph
class Graph{
    int size;
    int** edges;
    public:
        Graph(int s){
            if(s<2) size = 2;
            else size = s;
            edges = new int*[size];
            for(int i=0; i<size; i++){
                edges[i] = new int[size];
            }
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    edges[i][j] = 0;
                }
            }
        }
        
        ~Graph(){
            for(int i=0; i<size; i++){
                delete [] edges[i];
            }
            delete [] edges;
        }

        void addEdge(int u, int v){
            edges[u-1][v-1] = edges[v-1][u-1] = 1;
            return;
        }

        bool hasConnection(int u, int v){
            return edges[u-1][v-1] == 1;
        }

        string DFS(int start, int find){
            // String stream of path
            ostringstream oss;
            Stack *s = new Stack();
            bool *visited = new bool[size+1];
            for(int i=0; i<=size; i++){
                visited[i] = false;
            }
            // Add start to stack and record visited
            s->push(start);
            visited[start] = true;
            int current;
            while(!s->empty()){
                current = s->pop();
                oss << current << " ";
                if(current == find) return oss.str();
                for(int i=1; i<=size; i++){
                    if(hasConnection(current,i) && visited[i]==false){
                        s->push(i);
                        visited[i] = true;
                    }
                }
            }
            return "No path, sorry";
        }
        string BFS(int start, int find){
            // String stream of path
            ostringstream oss;
            Queue *q = new Queue();
            bool *visited = new bool[size+1];
            for(int i=0; i<=size; i++){
                visited[i] = false;
            }
            // Add start to queue and record visited
            q->enqueue(start);
            visited[start] = true;
            int current;
            while(!q->empty()){
                current = q->dequeue();
                oss << current << " ";
                if(current == find) return oss.str();
                for(int i=1; i<=size; i++){
                    if(hasConnection(current,i) && visited[i]==false){
                        q->enqueue(i);
                        visited[i] = true;
                    }
                }
            }
            return "No path, sorry";
        }
};


int main(int argc, char** argv){
    Stack myStack = Stack();
    myStack.push(1);
    Stack *stackAddr = &myStack;
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    stackAddr->push(5);
    stackAddr->push(6);
    myStack.pop();
    myStack.printStack();

    Queue myQueue = Queue();
    myQueue.enqueue(1);
    Queue *queueAddr = &myQueue;
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    queueAddr->enqueue(5);
    queueAddr->enqueue(6);
    myQueue.dequeue();
    myQueue.printQueue();
  
    Graph g(8);
    g.addEdge(1,2);  
    g.addEdge(1,3);  
    g.addEdge(1,4);  
    g.addEdge(2,5);  
    g.addEdge(2,6);  
    g.addEdge(4,7);  
    g.addEdge(5,8); 
    cout << g.hasConnection(1,2) << endl; 
    cout << g.hasConnection(1,4) << endl; 
    cout << g.hasConnection(2,5) << endl; 
    cout << g.hasConnection(2,7) << endl; 
    cout << g.hasConnection(4,1) << endl; 

    string dfsPath = g.DFS(1, 8);
    cout << dfsPath << endl;

    string bfsPath = g.BFS(1, 8);
    cout << bfsPath << endl;
    return 0;
}
