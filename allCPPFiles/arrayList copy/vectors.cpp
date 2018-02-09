/* Corey Garvey - July 5 */
/* Vectors in C++ */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    for(int i=1; i<4; i++){
        v.push_back(i);
    }
    int vsize = v.size();
    for(int i=0; i<vsize; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    vector<int>::iterator it = v.begin();
    v.insert(it+2, 12);
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "erase(it+1)" << endl;
    v.erase(it+1);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "pop_back" << endl;
    v.pop_back();
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
