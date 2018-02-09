/* Corey Garvey - July 19
 * HeapSort */

#include <iostream>

using namespace std;

void maxHeapify(int *arr, int size, int node){
    int largest = node;
    int left = largest*2 +1;
    int right = largest*2 +2;
    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != node){
        int tmp = arr[largest];
        arr[largest] = arr[node];
        arr[node] = tmp;
        maxHeapify(arr, size, largest);
    }
    return;
}

void heapSort(int *arr, int size){
    cout << "arr: " << arr << endl;;
    // maxHeapify Array
    for(int i=size/2-1; i>=0; i--){
        maxHeapify(arr, size, i);
    }
    //
    // "remove" highest value and maxHeapfiy
    for(int i=size-1; i>0; i--){
        int maxVal = arr[0];
        arr[0] = arr[i];
        arr[i] = maxVal;
        maxHeapify(arr, i, 0);
    }
    return;
}

void printArray(int *arr, int size){
    for(int i=0; i<size-1; i++){
        cout << arr[i] << "-";
    }
    cout << arr[size-1] << endl;
    return;
}

int main(int argc, char** argv){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(0);
    heapSort(arr, size);

    cout << "Sorted array is: " << endl;
    printArray(arr, size);
    return 0;
}
