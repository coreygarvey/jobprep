/* Corey Garvey - July 19
 * Heaps */

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Heap{
    vector<T> heap;
    public:
        Heap(){
            heap.push_back(NULL);
        }
        int getLeftChild(int parent){
            return parent*2;      
        }

        int getRightChild(int parent){
            return parent*2+1;
        }

        int getParent(int child){
            return child/2;
        }

        void insert(int val){
            heap.push_back(val);
            heapifyUp();
            return;
        }

        T remove(){
            int last = heap.size()-1;
            swap(last, 1);
            T item = heap[last];
            heap.pop_back();
            heapifyDown();
            return item;
        }
        int getSize(){
            return heap.size()-1;
        }
        int get(int index){
            return heap[index];
        }
        void swap(int first, int second){
            T tmp = heap[first];
            heap[first] = heap[second];
            heap[second] = tmp;
        }
        void heapifyUp(){
            int child = heap.size() - 1;
            int parent = getParent(child);
            while(heap[child] > heap[parent] && parent>0){
                swap(child, parent);
                child = parent;
                parent = getParent(child);
            }
            return;
        }

        void heapifyDown(){
            int parent = 1;
            while(1){
                int left = getLeftChild(parent);
                int right = getRightChild(parent);
                int largest = parent;
                if(heap[parent] < heap[left] && left<heap.size()){
                    largest = left;
                }
                if(heap[largest] < heap[right] && right<heap.size()){
                    largest = right;
                }
                if(largest != parent){
                    swap(largest, parent);
                    parent = largest;
                } else{
                    break;
                }
            }
            return;
        }
};

int main(int argc, char** argv){
    Heap<int>* myHeap = new Heap<int>();
    myHeap->insert(12);
    myHeap->insert(10);
    myHeap->insert(9);
    myHeap->insert(1);
    myHeap->insert(15);
    myHeap->insert(2);
    myHeap->insert(8);
    myHeap->insert(6);
    myHeap->remove();
    myHeap->remove();
    cout << "Size: " << myHeap->getSize() << endl;
    for(int i=1; i<=myHeap->getSize(); i++){
        cout << myHeap->get(i) << endl;
    }
    return 0;
}
