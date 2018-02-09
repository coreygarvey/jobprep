/* Corey Garvey - July 5
 * Dynamic Array - main file */

#include <iostream>
#include "dynamicArray.h"

using namespace std;

int main(int argc, char **argv){
    cout << "Dynamic array..." << endl;

    DynamicArray array = DynamicArray(4);
    array.insert(0, 12);
    array.insert(1, 43);
    array[2] = 56;
    array[3] = 75;

    DynamicArray array2 = DynamicArray(array);

    if(array == array2){
        cout << "Same arrays" << endl;
    }

    cout << "Original array size: " << array.getSize() << endl; 
    array[4] = 16;
    cout << "New array size: " << array.getSize() << endl;
    if(array != array2){
        cout << "Different arrays" << endl;
    }
    return 0;
}

