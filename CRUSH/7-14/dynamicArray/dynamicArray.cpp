/* Corey Garvey - July 14
 * Dynamic Arrays */

#include <iostream>

using namespace std;

class DynamicArray{
    int size;
    
    public:
        int *arr;

        DynamicArray(int initSize){
            size = initSize;
            arr = new int[size];
            for(int i=0; i<size; i++){
                arr[i] = 0;
            }
        }

        DynamicArray(const DynamicArray &original){
            size = original.size;
            arr = new int[size];
            for(int i=0; i<size; i++){
                arr[i] = original.arr[i];
            }
        }

        ~DynamicArray(){
            delete [] arr;
        }

        void insert(int index, int value){
            /*
            while(index > size){
                this.resize();
            }
            */
            arr[index] = value;
        }

        int get(int index){
            return arr[index];
        }
        
        int getSize(){
            return size;
        }

        void resize(){
            int newSize = size*2;
            //int tmp[newSize];
            int *tmp = new int[newSize];
            for(int i=0; i<size; i++){
                tmp[i] = arr[i];
            }
            delete [] arr;
            arr = tmp;
            
            size = newSize;
        }

        //bool operator==(const DynamicArray &original){
        bool operator==(const DynamicArray &original){
            if(size != original.size) return false;
            for(int i=0; i<size; i++){
                if(arr[i] != original.arr[i]) return false;
            }
            return true;
        }

        //bool operator!=(const DynamicArray &original){
        bool operator!=(const DynamicArray &original){
            if(size != original.size) return true;
            for(int i=0; i<size; i++){
                if(arr[i] != original.arr[i]) return true;
            }
            return false;   
        }


        int &operator[](int index){
            while(index >= size) this->resize();
            return arr[index];
        }
};

int main(int argc, char **argv){
    cout << "Dynamic arrays" << endl;

    DynamicArray array = DynamicArray(4);
    array.insert(0, 12);
    array.insert(1, 43);
    array[2] = 56;
    array[3] = 24;

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
