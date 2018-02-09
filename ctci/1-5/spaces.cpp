/* Corey Garvey - December 27 2017
 * Replace all spaces with '%20' */

#include <iostream>
using namespace std;

const int MAX=10000;

void replaceSpaces(char myString[]){
    int stringLen = strlen(myString);
    int numSpaces=0;
    for(int i=0; i<stringLen; i++){
        if(myString[i]==' '){
            numSpaces++;
        }
    }
    int newLength = stringLen + 2*numSpaces;

    myString[newLength] = '\0';
    for(int i=stringLen-1; i>=0; i--){
        if (myString[i] == ' '){
            myString[newLength-1] = '0';
            myString[newLength-2] = '2';
            myString[newLength-3] = '%';
            newLength = newLength-3;
        } else{
            myString[newLength-1] = myString[i];
            newLength = newLength-1;
        }
    }
    //return myString;
}

int main(int argc, char **argv){
    char myString[MAX] = "Hey here it is";
    cout << "myString: " << myString << endl;
    replaceSpaces(myString);
    cout << "myString: " << myString << endl;
    return 0;
}
