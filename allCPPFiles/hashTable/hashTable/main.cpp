/* Corey Garvey - July 5
 * Hash Table - main file */

#include "hashMap.cpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    cout << "HashTable" << endl;

    HashMap hm = HashMap();
    hm.put(5, 5);
    hm.put(200, 200);
    hm.put(2000, 2000);

    cout << hm.get(5) << endl;
    cout << hm.get(200) << endl;
    cout << hm.get(2000) << endl;

    return 0;
}
