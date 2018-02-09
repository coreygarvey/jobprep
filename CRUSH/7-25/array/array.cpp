/* Corey Garvey - July 25
 * Arrays */
#include <iostream>
using namespace std;

template<class T>
class Array {
    int size;
    T* list;
    public:
        Array(int initSize) {
            size = initSize;
            T* tmp = new T[size];
            list = tmp;
        }
        Array(int initSize, T initVal){
            size = initSize;
            T* tmp = new T[size];
            for(int i=0; i<size; i++){
                tmp[i] = initVal;
            }
            list = tmp;
        }
        
        Array(Array* initArray){
            int initSize = initArray->getSize();
            size = initSize;
            T* tmp = new T[size];
            for(int i=0; i<size; i++){
                tmp[i] = initArray->list[i];
            }
            list = tmp;
        }
        ~Array(){
            delete [] list;
        }
        
        int getSize(){
            return size;
        }

        T operator[] (int index){
            return list[index];
        }
        bool operator== (Array* compArray){
            if(compArray->getSize() != size){
                cout << "Not a match" << endl;
                return false;
            }
            for(int i=0; i<size; i++){
                if(compArray[i] != list[i]){
                    cout << "Mismatch at " << i << endl;
                    return false;
                }
            }
            cout << "Matching arrays" << endl;
            return true;
        }

        void operator=(Array* newArray){
            int newSize = newArray->getSize();
            size = newSize;
            T* newList = new T[size];
            for(int i=0; i<size; i++){
                newList[i] = newArray[i];
            }
        }
        template<class U>
        friend ostream& operator<<(ostream&, const Array<U>&);
};

template <class T>
ostream& operator<<(ostream& outstream, const Array<T>& outArray){
    int arraySize = outArray.size;
    cout << "Got size: " << arraySize << endl;
    int i;
    for(i=0; i<arraySize-1; i++){
        outstream << outArray.list[i] << "-";
    }
    outstream << outArray.list[i] << endl;
    return outstream;
}

int main(int argc, char** argv){
    int size = 5;
    Array<int>* intArray = new Array<int>(size, 6);
    Array<int>* anotherArray = new Array<int>(size, 3);
    intArray[2] = 5;
    if(intArray == anotherArray){
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }
    cout << *intArray << endl;
    intArray = anotherArray;
    if(intArray == anotherArray){
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    cout << *intArray << endl;
    return 0;
}
