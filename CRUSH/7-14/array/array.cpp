/* Corey Garvey - July 14
 * Array */

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Array{
    private:
        T *arr;
    public:
        int size;
        explicit Array(const int& initSize){
            arr = new T[initSize];
            size = initSize;
        }
        Array(const int& initSize, const T& initVal){
            arr = new T[initSize];
            size = initSize;
            for(int i=0; i<initSize; i++){
                arr[i] = initVal;
            }
        }

        T& operator[](int index){
            return arr[index];
        }

        Array(const Array& originalArray){
            size = originalArray.size;
            arr = new T[size];
            for(int i=0; i<size; i++){
                arr[i] = originalArray.arr[i];
            }
        }

        ~Array(){
            delete [] arr;
        }

        
        Array<T>& operator=(Array inputArray){
            swap(size, inputArray.size);
            swap(arr, inputArray.arr);
        }

        friend ostream& operator<< (ostream& out, const Array<T>& self){
            out << "[ ";
            for(int i=0; i<self.size-1; i++){
                out << self.arr[i] << ",";
            }
            out << self.arr[self.size-1] << " ]";
            return out;
        }
        
};

int main(int argc, char **argv){
    Array<string> firstArray = Array<string>(5, "corey");
    cout << "firstArray: " << endl;
    cout << firstArray << endl;

    for(int i=0; i<firstArray.size; i++){
        firstArray[i] = "meghan";
    }

    cout << "firstArray: " << endl;
    cout << firstArray << endl;

    Array<string> secondArray = Array<string>(5, "tom");
    firstArray = secondArray;

    cout << "firstArray: " << endl;
    cout << firstArray << endl;

    return 0;
}
