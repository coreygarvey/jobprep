/* Corey Garvey - July 20
 * StringBuffer */
#include <iostream>

using namespace std;

class StringBuffer{
    int capacity;
    int length;
    char *buffer;
    public:
        StringBuffer(int l){
           capacity = l;
           buffer = new char[capacity];
           length = 0;
        }

        ~StringBuffer(){
            delete [] buffer;
        }

        void append(string str){
            string s = str;
            if(s.empty()) s = "null";
            int strSize = s.size();
            if(length + strSize > capacity){
                // Determine new size
                int doubleSize = capacity*2;
                int bothSize = length+strSize+1;
                int newSize = doubleSize > bothSize ? doubleSize : bothSize;
                // Create new array and copy buffer
                capacity = newSize;
                char *tmp = new char[capacity];
                for(int i=0; i<length; i++){
                    tmp[i] = buffer[i];
                }
                // Reassign buffer
                delete [] buffer;
                buffer = tmp;
            }
            if(length>0){
                // Add space
                buffer[length] = ' ';
                length++;
            }
            // Append new string
            for(int i=0; i<strSize; i++){
                buffer[length] = str.at(i);
                length++;
            }
            return;
        }

        string toString(){
            cout << "Capacity: " << capacity << endl;
            string s;
            for(int i=0; i<length; i++){
                s += buffer[i];
            }
            return s;
        }
};

int main(int argc, char** argv){
    StringBuffer *myBuffer = new StringBuffer(5);
    myBuffer->append("corey");
    myBuffer->append("hey");
    string currentBuff = myBuffer->toString();
    cout << currentBuff << endl;
    myBuffer->append("Corey Garvey");
    currentBuff = myBuffer->toString();
    cout << currentBuff << endl;
    return 0;
}

