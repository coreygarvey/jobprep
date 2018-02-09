/* Corey Garvey - July 21
 * MergeSort */

#include <iostream>

using namespace std;

void merge(int *arr, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int *L = new int[n1];
    int *R = new int[n2];
    int i;
    for(i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(i=0; i<n2; i++){
        R[i] = arr[m+1+i];
    }

    i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    return;
}

void mergeSort(int *arr, int first, int last){
    if(first < last){
        int mid = (first+last)/2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);
        merge(arr, first, mid, last);
    }   
    return;
}
void printArr(int *arr, int size){
    cout << "Array: " << endl;
    int i;
    for(i=0; i<size-1; i++){
        cout << arr[i] << "-";
    }
    cout << arr[i] << endl;
}

int main(int argc, char** argv){
    int arr[] = {12, 14, 4, 9, 1, 6, 10};
    int size = sizeof(arr)/sizeof(0);
    printArr(arr, size);
    
    mergeSort(arr,0,size-1);

    printArr(arr, size);

    return 0;
}
