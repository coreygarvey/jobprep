/* Corey Garvey - July 12
 * Remove Dupes from string in place */

#include <iostream>
#include <map>
using namespace std;

void removeDupes(char theString[]){
    if(theString == nullptr) return;
    int innerIndex, outerIndex;
    int stringLen = strlen(theString);
    if(stringLen < 2) return;
    for (outerIndex = 0; outerIndex<stringLen-1; outerIndex++){
        for (innerIndex = outerIndex+1; innerIndex<stringLen; innerIndex++){
            if(theString[outerIndex] == theString[innerIndex]){
                stringLen = stringLen-1;
                for(int i=innerIndex; i<stringLen; i++){
                    theString[i] = theString[i+1];
                }
                theString[stringLen]=0;;
            }
        }
    }
    return;
}

// Create a map for all characters and
//  Check if letter has been seen.
void removeDupes2(char theString[]){
    if(theString == nullptr) return;
    map<char, bool> tracker;
    int stringLen = strlen(theString);
    if(stringLen < 2) return;
    for(int i=0; i<256; i++){
        tracker[i] = false;
    }
    tracker[theString[0]] = true;
    int tail = 1;
    for(int i=1; i<stringLen; i++){
        if(tracker[theString[i]]==false) {
            theString[tail] = theString[i];
            tail++;
            tracker[theString[i]] = true;
        }
    }
    theString[tail] = 0;
}    

int main(int argc, char **argv){
    char myString[] = "tommy";
    removeDupes(myString);
    cout << myString << endl;
    char myString2[] = "billy";
    removeDupes2(myString2);
    cout << myString2 << endl;
    return 0;
}
