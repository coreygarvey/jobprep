/* Corey Garvey - July 5
 * Hash table in C++ */

#include <iostream>
#include <string>
#include <map>
#include <cassert>
using namespace std;

int main() {
    cout << "Implementing a hash table" << endl;
    
    // Create array of students
    string students[] = {"Corey", "Bridget", "Julie"};    
    int student_count = 3;
    for (int i=0; i<student_count; i++){
        cout << students[i] << " ";
    }
    cout << endl;
    // Create hash Table
    map<int, string> hashTable;
    for (int i=12; i<15; i++){
        hashTable[i] = students[i-12];
    }
    // Loop through hashTable
    map<int, string>::iterator it;
    for (it=hashTable.begin(); it!=hashTable.end(); it++){
        cout << it->second << endl;
    }
    
    // Find value based on hash 
    it = hashTable.find(12);
    assert(it != hashTable.end());
    cout << it->first << ":" << it->second << endl;
    return 0;
}
