/* Corey Garvey - July 19
 * Array */

#include <iostream>
using namespace std;

template <class T>
class Array{
    int size;
    T* list;
    public:
        template<class U>
        friend ostream& operator<<(ostream&, const Array<U>&);
        Array(int initSize){
            size = initSize;
            list = new T[size];
        }
        Array(int initSize, int val){
            size = initSize;
            list = new T[size];
            for(int i=0; i<size; i++){
                list[i] = val;
            }
        }
        Array(const Array& original){
            size = original.size;
            list = new T[size];
            for(int i=0; i<size; i++){
                list[i] = original.list[i];
            }
        }
        ~Array(){
            delete [] list;
        }
        T& operator[](int index){
            return list[index];
        }
        bool operator==(const Array& compArray){
            if(this == &compArray){
                return true;
            }
            if(compArray.size != size){
                return false;
            }
            for(int i=0; i<size; i++){
                if(compArray.list[i] != list[i]){
                    return false;
                }
            }
            return true;
        }
        void operator=(const Array& newArray){
            size = newArray.size;
            T* tmpList = new T[size];
            for(int i=0; i<newArray.size; i++){
                tmpList[i] = newArray.list[i];
            }
            delete [] list;
            list = tmpList;
            return;
        }
};
template <class T>
ostream& operator<<(ostream& outstream, const Array<T>& self){
    for(int i=0; i<self.size-1; i++){
        outstream << self.list[i] << "-";
    }
    outstream << self.list[self.size-1] << endl;
    return outstream;
}

int main(int argc, char** argv){
    Array<int> myArray = Array<int>(5, 1);
    Array<int> yourArray = Array<int>(5, 3);
    if(myArray == yourArray){
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }
    myArray = yourArray;
    if(myArray == yourArray){
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }
    myArray[3] = 2;
    cout << myArray;
}
