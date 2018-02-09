/* Corey Garvey - July 6
 * String Stream Examples */

#include <sstream>
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    // int to be used for concats
    int four = 4;

    // Output string stream
    //  different datatypes to string
    ostringstream ss;
    ss << four << ", " << 5.5 << "!!";
    string str = ss.str();
    cout << str << endl;
    
    // Input string stream
    //  string of ints to ints
    //  stops upon reaching .
    string str2 = "1 2 3.1";
    istringstream si(str2);
    int x;
    // Loop through input stream
    while (si >> x)
        cout << x << " ";
    cout << endl;

    // String concatenation
    //  Cannot append number to string 
    string str3;
    str3 = "Cannot append number to string: ";
    str3 += four;
    cout << str3 << endl;
    return 0;
}
