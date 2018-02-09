/* Corey Garvey - July 12 2017
 * All Unique Characters in String */
#include <map>
#include <iostream>
using namespace std;

void allUniqueStruct(char myString[]){
    char *iterator = myString;
    map<char, int> letters;
    while(*iterator){
        if(letters[*iterator] == 1){
            cout << "Not Unique" << endl;
            return;
        }
        else{
            letters[*iterator] = 1;
        }
        iterator++;
    }
    cout << "Unique" << endl;
    return;
    
}

void allUniqueNoStruct(char myString[]) {
   char *outerIterator = myString;
   char outerChar = *outerIterator;
   char *innerIterator = ++outerIterator;
   while(*outerIterator) {
       while(*innerIterator) {
           char innerChar = *innerIterator;
           if(innerChar == outerChar){
               cout << "Not Unique" << endl;
               return;
           }
           innerIterator++;
       }
       outerChar = *outerIterator;
       innerIterator = ++outerIterator;
   }
   cout << "Unique" << endl;
   return;
}

// Using an int's binary representation to track
//  occurance of lowercase letters
void allUniqueNoStruct2(char myString[]){
    // Checker will keep track of each letter
    //  as a 1 in its binary representation
    int checker = 0;
    int val;
    for(int i=0; i < strlen(myString); i++){
        val = myString[i] - 'a';
        if((checker & ( 1 << val)) > 0){
            cout << "Not Unique" << endl;
            return;
        }
        // Update checker to include 1 in 
        //  correct place for val
        checker = checker | (1 << val);
    }
    cout << "Unique" << endl;
    return;
}

int main(int argc, char **argv){
    char dupeString[] = "tommy";
    char uniqueString[] = "corey";
    allUniqueStruct(dupeString);
    allUniqueStruct(uniqueString);
    
    allUniqueNoStruct(dupeString);
    allUniqueNoStruct(uniqueString);
    
    allUniqueNoStruct2(dupeString);
    allUniqueNoStruct2(uniqueString);
    return 0;
}
