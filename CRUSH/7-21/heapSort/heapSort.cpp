/* Corey Garvey - July 21
 * Bubble Sort */
#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Max heapify makes the highest at the top
void maxHeapify(int* arr, int size, int node){
    // set largest = node
    int largest = node;
    // get left and right
    int left = largest*2+1;
    int right = largest*2+2;
    // get largest of left, right, largest
    if(arr[left] > arr[largest] && left < size){
        largest = left;
    }
    if(arr[right] > arr[largest] && right < size){
        largest = right;
    }
    // if largest!= node
    if(largest != node){
        //  swap largest with node
        swap(&arr[largest], &arr[node]);
        //  maxHeapify(arr, size, largest)
        maxHeapify(arr, size, largest);
    }
}

// Sorting with lowest at the beginning
void heapSort(int* arr, int size){
    // maxHeapify from size/2 to 0
    for(int i=(size/2-1); i>=0; i--){
        maxHeapify(arr, size, i);
    }
    // from end to front
    for(int i=size-1; i>0; i--){
        //  swap largest and back
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        //  max heapify from 0 with size = size-1
        maxHeapify(arr, i, 0);
    }
    return;

}

void printArr(int* arr, int size){
    int i;
    for(i=0; i<size-1; i++){
        cout << arr[i] << "-";
    }
    cout << arr[i] << endl;
    return;
}

int main(int argc, char** argv){

    int arr[] = {12, 1, 3, 14, 9, 2, 10};
    int size = sizeof(arr)/sizeof(0);
    cout << "before sort: " << endl;
    printArr(arr, size);

    heapSort(arr, size);

    cout << "after sort: " << endl;
    printArr(arr, size);
}
