/* Corey Garvey - July 14
 * Hash Map */

#include <iostream>

using namespace std;

class hashElement{
    int key;
    int value;

    public:
        hashElement(int initKey, int initValue):
            key(initKey), value(initValue) {}
        int getKey(){
            return key;
        }
        int getValue(){
            return value;
        }
};

const  int MAP_SIZE = 128;
class hashMap{
    hashElement **arr;
    public:
        hashMap(){
            arr = new hashElement*[MAP_SIZE];
            for(int i=0; i<MAP_SIZE; i++){
                arr[i] = nullptr;
            }
        }
        void put(int key, int value){
            int index = key % MAP_SIZE;
            while(arr[index] != NULL && arr[index]->getKey() != key){
                index = (index+1) % MAP_SIZE;
            }
            if(arr[index] != NULL){
                delete arr[index];
            }

            arr[index] = new hashElement(key,value);
        }

        int get(int key){
            int index = key % MAP_SIZE;
            while(arr[index] != NULL && arr[index]->getKey() != key){
                index = (index+1) % MAP_SIZE;
            }
            if(arr[index] == NULL){
                return -1;
            }
            return arr[index]->getValue();  
        }
        ~hashMap(){
            for(int i=0; i<MAP_SIZE; i++){
                if(arr[i] != nullptr){
                    delete [] arr[i];
                }
            }
            delete [] arr;
        }
};


int main(int argc, char** argv){
    cout << "HashMap" << endl;

    hashMap *myMap = new hashMap();
    myMap->put(240, 12);
    myMap->put(460, 13);
    myMap->put(112, 14);
    myMap->put(241, 15);
    cout << myMap->get(241) << endl;
    return 0;
}
