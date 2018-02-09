/* Corey Garvey - July 11
 * Array Class */

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Array{
    public:
        explicit Array(const int&);
        Array(const int&, const T&);
        Array(const Array&);
        virtual ~Array();
        //T getVal(const int&) const;
        //void setVal(const int&, const T&);
        T& operator[](int);
        //Array& operator= (const Array&);
        Array& operator= (Array);
        
        template <class U>
        friend ostream& operator<< (ostream&, const Array<U>&);
    private:
        T *arr;
        int size;
};

template <class T>
Array<T>::Array(const int& init_size):
    arr(new T[init_size]), size(init_size)
{}

template <class T>
Array<T>::Array(const int& init_size, const T& init_val){
    arr = new T[init_size];
    size = init_size;
    for(int i=0; i<init_size; i++){
        arr[i] = init_val;
    }
}

template <class T>
Array<T>::Array(const Array& original){
    size = original.size;
    arr = new T[size];
    for(int i=0; i<size; i++){
        arr[i] = original.arr[i];
    }
}

template <class T>
Array<T>::~Array(){
    delete [] arr;
}
/*
template <class T>
T Array<T>::getVal(const int& index) const{
    return arr[index];
}

template <class T>
void Array<T>::setVal(const int& index, const T& val){
    arr[index] = val;
}
*/
template <class T>
T& Array<T>::operator[](int index){
    return arr[index];
}
/*
template <class T>
Array<T>& Array<T>::operator= (const Array& copy){
    // Return if assigning to self
    if(this == &copy){
        return *this;
    }
    // Do operations that don't touch object first
    T *tmp = new T[size];
    for(int i=0; i<size; i++){
        tmp[i] = copy.arr[i];
    }
    
    // swap *tmp into arr
    swap(tmp, arr);
    size = copy.size;
    // delete tmp because already swapped in
    delete [] tmp;
    return *this;

    // Alternatively: Copy and Swap Idiom
}
*/
template<class T>
Array<T>& Array<T>::operator= (Array input){
    swap(size, input.size);
    swap(arr, input.arr);
}

template <class T>
ostream& operator<< (ostream& out, const Array<T>& self){
    out << "[ ";
    for (int i=0; i<self.size-1; i++){
        out << self.arr[i] << ",";
    }
    out << self.arr[self.size-1] << " ]";
    return out;
}

int main(int argc, char **argv){
    Array<string> stringArray = Array<string>(10, "corey");
    cout << stringArray[0] << endl;
    stringArray[1] = "tom";
    cout << stringArray << endl;
    
    Array<int> intArray = Array<int>(10, 4);
    cout << intArray[0] << endl;
    intArray[1] = 11;
    cout << intArray << endl;
    return 0;
}
