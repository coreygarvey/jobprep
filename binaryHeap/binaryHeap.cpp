/* Corey Garvey - July 13
 * Binary Heap */

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class BinaryHeap {
   vector<T> heap;

    void heapifyUp();
    void heapifyDown();
    void swap(int child, int parent);
    int getLeftChild(int parent);
    int getRightChild(int parent);
    int getParent(int child);
  public:
    BinaryHeap();
    void insert(T);
    T remove();
    int getSize();
};

template <class T>
BinaryHeap<T>::BinaryHeap(){
}

template <class T>
int BinaryHeap<T>::getSize(){
    //return heap.size();
    return heap.size()-1;
}

template <class T>
void BinaryHeap<T>::swap(int child, int parent){
    T tmp = heap[child];
    heap[child] = heap[parent];
    heap[parent] = tmp;
}

template <class T>
int BinaryHeap<T>::getParent(int child){
    /*if(child % 2 == 0){
        return (child/2) - 1;
    } else{
        return (child/2);
    }
    */
    return (child/2);
}

template <class T>
int BinaryHeap<T>::getLeftChild(int parent){
    //return (2*parent) + 1;
    return (2*parent);
}

template <class T>
int BinaryHeap<T>::getRightChild(int parent){
    //return (2*parent) + 2;
    return (2*parent) + 1;
}

template <class T>
void BinaryHeap<T>::insert(T value) {
    //heap.push_back(value);
    if(heap.size() == 0){
        heap.push_back(0);
        heap.push_back(value);
    } else{
        heap.push_back(value);
    }
    heapifyUp();
}

template <class T>
void BinaryHeap<T>::heapifyUp() {
    /*
     * Take the last element
     * Check if it's bigger than its parent
     * while it's bigger than it's parent, swap with parent and run it again
     */
    //int child = heap.size() - 1;
    int child = heap.size() - 1;
    int parent = getParent(child);
    //while (heap[child] > heap[parent] && child >= 0 && parent >= 0){
    while (heap[child] > heap[parent] && child >= 1 && parent >= 1){
        swap(child, parent);
        child = parent;
        parent = getParent(child);
    }
}


template <class T>
T BinaryHeap<T>::remove(){
   //int child = heap.size() - 1;
   int child = heap.size() - 1;
   //swap(child, 0);
   swap(child, 1);
   
   T value = heap.back();
   heap.pop_back();

   heapifyDown();
   return value;
}


template <class T>
void BinaryHeap<T>::heapifyDown() {
    /*
     * Get digit at 0 = parent
     * compare with child
     * while smaller than child, swap
     */
   //int parent = 0;
   int parent = 1;

   while(1) {

      int left = getLeftChild(parent);
      int right = getRightChild(parent);
      int length = heap.size();
      int largest = parent;

      if(heap[left] > heap[largest] && left < length){
         largest = left;
      }
       
      if(heap[right] > heap[largest] && right < length){
         largest = right;
      }

      if(largest != parent){
          swap(parent, largest);
          parent = largest;
      }
      else {
          break;
      }
   }
}

int main(){
    int a[] = {4, 6, 9, 3, 5, 1, 11, 8};
    BinaryHeap<int> heap;

    int len = sizeof(a)/sizeof(0);
    for(int i = 0; i<len; i++){
        heap.insert(a[i]);
    }

    while(heap.getSize()>0){
        cout << "Heap Max Value: " << heap.remove() << endl;
    }
    
    return 0;
}
