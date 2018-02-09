/* Corey Garvey - July 21
 * Bubble Sort */
#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int* arr, int size){
    
    for(int i=0; i<size; i++){

        for(int j=0; j<size-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
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

    bubbleSort(arr, size);

    cout << "after sort: " << endl;
    printArr(arr, size);
}

