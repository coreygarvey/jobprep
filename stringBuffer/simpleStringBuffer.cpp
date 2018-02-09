/* Corey Garvey - July 6
 * Simple String Buffer */
#include <string>
#include <stddef.h>
#include "simpleStringBuffer.h"
using namespace std;

/*
SimpleStringBuffer::SimpleStringBuffer(){
    SimpleStringBuffer::SimpleStringBuffer(16);
}
*/
// Default length in header. Above is for C++11
SimpleStringBuffer::SimpleStringBuffer(int l){
    capacity = l;
    buffer = new char[capacity];
    length = 0;
}

SimpleStringBuffer::~SimpleStringBuffer(){
    delete[] buffer;
}

void SimpleStringBuffer::append(string str){
    string s = str;
    if(s.empty()) s = "null";
    // check length and create bigger buffer if needed
    if(length+s.size() > capacity){
        // determine larger, new len or capacity*2
        int a = length+s.size();
        int b = capacity*2;
        int len = a > b ? a : b;
        // create temporary buffer
        char *tmp;
        tmp = new char[len];
        // copy buffer to temp
        for(int i=0; i<length; i++){
            tmp[i] = buffer[i];
        }
        // delete old buffer, reassign var to temp
        delete[] buffer;
        buffer = tmp;
        capacity = len;
    }
    // Add space
    buffer[length] = ' ';
    length += 1;
    for(int i=0; i<s.size(); i++){
        buffer[length+i] = s.at(i);
    }
    length += s.size();
}

string SimpleStringBuffer::toString() {
    string s;
    for (int i = 0; i<length; i++){
        s += buffer[i];
    }
    return s;
}
