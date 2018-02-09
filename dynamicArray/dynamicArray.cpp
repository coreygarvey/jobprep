/* Corey Garvey - July 5 */
/* Dynamic Array Class */

#include "dynamicArray.h"

DynamicArray::DynamicArray(){
    DynamicArray::DynamicArray(5);
}

DynamicArray::DynamicArray(int initSize){
    size = initSize;
    array = new int[size];
    for(int i=0; i<size; i++){
        array[i]=0;
    }
}

DynamicArray::DynamicArray(const DynamicArray &original){
    size = original.size;
    array = new int[size];
    for(int i=0; i<size; i++){
        array[i] = original.array[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] array;
}

void DynamicArray::insert(int position, int value){
    array[position] = value;
}

int DynamicArray::get(int position){
    return array[position];
}

int DynamicArray::getSize(){
    return size;
}

void DynamicArray::resize(){
    // Can we double?
    int newSize = size*2;
    int *tmp; 
    tmp = new int[newSize];
    for (int i=0; i<size; i++){
        tmp[i] = array[i];
    }
    delete[] array;
    array = tmp;
    size = newSize;
}

bool DynamicArray::operator==(DynamicArray a){
    if (a.size != size){
        return false;
    }
    for (int i=0; i<a.size; i++){
        if(a[i] != array[i]){
            return false;
        }
    }
    return true;
}

bool DynamicArray::operator!=(DynamicArray a){
    if (a.size != size){
        return true;
    }
    for (int i=0; i<a.size; i++){
        if(a[i] != array[i]){
            return true;
        }
    }
    return false;
}

int &DynamicArray::operator[](int index) {
    if(index>(size+1){
        resize();
    }
    return(array[index]);
}
