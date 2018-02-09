/* Corey Garvey - July 21
 * Selection Sort */
#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int* arr, int size){
    
    for(int i=0; i<size-1; i++){
        int mindex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[mindex]){
                mindex = j;
            }
        }
        swap(&arr[mindex], &arr[i]);
    }
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

    selectionSort(arr, size);

    cout << "after sort: " << endl;
    printArr(arr, size);
}

