/* Corey Garvey - July 5
 * Dynamic Array List */
#include <iostream>
#include <vector>

using namespace std;

int *nums;
int size;

// Dynamic array
void A (int* &arr){
    // New array
    int *resize;
    // New array is double the size
    resize = new int[size*2];
    
    // Fill in at the new array 
    for (int i=0; i<size; i++){
        resize[i] = arr[i];
    }
    cout << endl;
    delete[] arr;
    arr = resize;
    size *= 2;
}
int main() {

    // Create array, whenever it gets too big, double size
    size = 8;
    nums = new int[size];
    for(int i=0; i<size; i++){
        nums[i] = i;
    }
    for(int i=0; i<size; i++){
        cout << nums[i] << endl;
    }

    A(nums);
    cout << "size: " << size << endl;

    for(int i=(size/2); i<size; i++){
        nums[i] = i;
    }

    for(int i=0; i<size; i++){
        cout << nums[i] << endl;
    }

    return 0;
}

