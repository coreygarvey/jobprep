/* Corey Garvey - July 6
 * SimpleStringBuffer - main file */
#include <string>
#include <iostream>
#include "simpleStringBuffer.h"

using namespace std;

int main(){
    // Will use default length because it isn't defined
    SimpleStringBuffer ssb = SimpleStringBuffer();
    
    string word1 = "first_word";
    string word2 = "second_word";
    
    ssb.append(word1);
    string oneWord = ssb.toString();
    cout << oneWord << endl;

    ssb.append(word2);
    string twoWords = ssb.toString();
    cout << twoWords << endl;
    
    return 0;

}
