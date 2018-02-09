/* Corey Garvey - July 19
 * HashMap */
#include <iostream>
using namespace std;

struct HashElement{
    int key;
    int value;
};

class HashMap{
    int size;
    HashElement** arr;
    public:
        HashMap(int initSize){
            size = initSize;
            arr = new HashElement*[size];
            for(int i=0;i<size;i++){
                arr[i] = nullptr;
            }
        }
        
        int get(int key){
            int index = key % size;
            while(arr[index]->key!=key && arr[index]!=nullptr){
                index += 1;
            }
            if(arr[index]==NULL){
                cout << "Sorry, not here" << endl;
            }
            return arr[index]->value;
        }

        int put(int key, int value){
            HashElement* newElement = new HashElement;
            newElement->key = key;
            newElement->value = value;
            int index = key % size;
            while(arr[index]!=nullptr && arr[index]->key!=key){
                index += 1;
                index = index % size;
            }
            arr[index] = newElement;
            return index;
        }   
        ~HashMap(){
            delete [] arr;
        }
};


int main(int argc, char** argv){
    const int MAP_SIZE = 128;
    HashMap* myMap = new HashMap(MAP_SIZE);
    myMap->put(1, 1);
    myMap->put(2, 2);
    myMap->put(129, 129);
    int getVal = myMap->get(129);
    cout << "get(129): " << getVal << endl;
    return 0;
}
