/* Corey Garvey - July  14
 * Binary Heap */

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class BinaryHeap{
    vector<T> list;
    int getLeftChild(int parent){
        return parent*2;
    }
    
    int getRightChild(int parent){
        return parent*2 + 1;
    }

    int getParent(int child){
        return child/2;
    }

    void swap(int val1, int val2){
        T tmp = list[val1];
        list[val1] = list[val2];
        list[val2] = tmp;
        return;
    }

    void heapifyUp(){
        int child = list.size() - 1;
        int parent = getParent(child);
        while(list[child] > list[parent] && parent >= 1){
            swap(child, parent);
            child = parent;
            parent = getParent(child);
        }
        return;
    }

    void heapifyDown() {
        int parent = 1;

        while(1){
            int left = getLeftChild(parent);
            int right = getRightChild(parent);
            int largest = parent;

            if(list[largest] < list[left] && left < list.size()){
                largest = left;
            }
            if(list[largest] < list[right] && right < list.size()){
                largest = right;
            }
            if(largest != parent){
                swap(largest, parent);
                parent = largest;
            } else {
                break;
            }
        }
        return;
    }

    public:
        BinaryHeap(){
            list.push_back(NULL);
        }


        T remove(){
            int last = list.size() - 1;
            swap(1, last);
            T value = list[last];
            list.pop_back();
            heapifyDown();
            return value;
        }
        
        void insert(T value){
            list.push_back(value);
            heapifyUp();
            return;
        }

        int getSize(){
            return list.size()-1;       
        }
        T get(int index){
            return list[index];
        }

};



int main(int argc, char **argv){
    
    int a[] = {4, 6, 9, 3, 5, 1, 11, 8};
    BinaryHeap<int> heap;

    int len = sizeof(a)/sizeof(0);
    for(int i=0; i<len; i++){
        heap.insert(a[i]);
        cout << heap.getSize() << endl;
        for(int i=0; i<heap.getSize(); i++){
            cout << heap.get(i) << "-";
        }
        cout << endl;
    }

    while(heap.getSize()>0){
        cout << "Heap Max Value: " << heap.remove() << endl;
    }

    return 0;
}
