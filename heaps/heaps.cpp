/* Corey Garvey - July 11
 * Heap */

#include <iostream>
using namespace std;

// Organize array into max heap
void maxHeapify(int *a, int i, int n){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<=n && a[left]>a[i]){
        largest = left;
    }
    if(right<=n && a[right]>a[largest]){
        largest = right;
    }
    if(largest != i){
        int tmp = a[largest];
        a[largest] = a[i];
        a[i] = tmp;
        cout << endl;
        cout << "Inside maxHeapify()" << endl;
        cout << "i: " << i << endl;
        cout << "n: " << n << endl;
        cout << "tmp: " << tmp << endl;
        cout << "largest: " << largest << endl;
        cout << "left: " << left << endl;
        cout << "right: " << right << endl;
        for(int i=1; i<=n; i++){
            cout << a[i] << " ";
        }
        cout << endl << endl;
        maxHeapify(a, largest, n);
    }
}

// Build heap from array
void buildHeap(int *a, int n){
    for(int i=n/2; i>=1; i--){
        maxHeapify(a, i, n);
    }
}

// Sort heap
void heapSort(int *a, int n){
    //buildHeap(a, n);
    int tmp;
    for(int i=n; i>=2; i--){
        tmp = a[i];
        // Put largest item a[1], at proper position
        a[i] = a[1];
        a[1] = tmp;
        cout << endl;
        cout << "Inside heapSort()" << endl;
        cout << "i: " << i << endl;
        for(int i=1; i<=n; i++){
            cout << a[i] << " ";
        }
        cout << endl << endl;
        // Heapify from 1 to n-1, after n-1 has been sorted
        maxHeapify(a, 1, i-1);
    }
}
        
int main(int argc, char ** argv){
    int SIZE = 5;
    int n = SIZE;
    int a[SIZE];
    cout << "Enter values for array: " << endl;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cout << "Before buildHeap()" << endl;
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    buildHeap(a, SIZE);
    cout << "After buildHeap(), before heapSort()" << endl;
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    heapSort(a, SIZE);
    cout << "After heapSort()" << endl;
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
