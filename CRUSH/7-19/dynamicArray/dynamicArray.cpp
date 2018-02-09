/* Corey Garvey - July 19
 * Dynamic Array */

#include <iostream>

using namespace std;

template <class T>
class DynamicArray{
    int size;
    T* list;
    public:
        DynamicArray(int initSize){
            size = initSize;
            list = new T[size];
        }
        DynamicArray(const DynamicArray& original){
            size = original.size;
            list = new T[size];
            for(int i=0; i<size; i++){
                list[i] = original.list[i];
            }
        }
        ~DynamicArray(){
            delete [] list;
        }
        void insert(int index, T val){
            while(index >= size){
                resize();
            }
            list[index] = val;
        }
        T get(int index){
            return list[index];
        }
        void resize(){
            int newSize = size*2;
            T* tmpList = new T[newSize];
            for(int i=0; i<size; i++){
                tmpList[i] = list[i];
            }
            size = newSize;
        }
        bool operator==(const DynamicArray& compArray){
            if(this == &compArray){
                return true;
            }
            if(size != compArray.size){
                return false;
            }
            for(int i=0; i<size; i++){
                if(list[i] != compArray.list[i]){
                    return false;
                }
            }
            return true;
        }
        bool operator!=(const DynamicArray& compArray){
            if(this == &compArray){
                return false;
            }
            if(size != compArray.size){
                return true;
            }
            for(int i=0; i<size; i++){
                if(list[i] != compArray.list[i]){
                    return true;
                }
            }
            return false;
        }
        T& operator[](int index){
            return list[index];
        }
};
int main(int argc, char** argv){
    DynamicArray<int> myArray = DynamicArray<int>(5);
    DynamicArray<int> yourArray = DynamicArray<int>(5);
    for(int i=0;i<5;i++){
        myArray[i] = i;
        yourArray[i] = i;
    }
    if(myArray == yourArray){
        cout << "Equal" << endl;
    }
    if(myArray != yourArray){
        cout << "Not Equal" << endl;
    }
    myArray[3] = 2;
    if(myArray == yourArray){
        cout << "Equal" << endl;
    }
    if(myArray != yourArray){
        cout << "Not Equal" << endl;
    }
    for(int i=0; i<5; i++){
        cout << myArray[i];
    }
    cout << endl;
} 
        
