/* Corey Garvey - January 24 2018
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

        Array(int initSize, T val){
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
            if(size != compArray.size){
                return false;
            }
            for (int i=0;i<size;i++){
                if(list[i] != compArray.list[i]){
                    return false;
                }
            }
            return true;
        }

        void operator=(const Array& newArray){
            int size = newArray.size;
            T* tmpList = new T[size];
            for(int i=0; i<size; i++){
                tmpList[i] = newArray.list[i];
            }
            delete [] list;
            list = tmpList;
            return;
        }

};

template <class T>
ostream& operator<<(ostream& outstream, const Array<T>& array){
    for(int i=0; i<array.size-1; i++){
        outstream << array.list[i] << "-";
    }
    outstream << array.list[array.size-1] << endl;
    return outstream;
}


int main(int argc, char** argv){
    Array<int> myArray = Array<int>(5, 1);
    Array<int> yourArray = Array<int>(5,3);

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

    Array<char> charArray = Array<char>(6, 'A');
    cout << charArray;
}
