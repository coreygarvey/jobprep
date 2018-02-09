/* Corey Garvey - December 27 2017
 * Method to determine if 2 strings are anagrams */
#include <iostream>
using namespace std;

bool anagrams(char string1[], char string2[]){
    // Anagrams have all the same letters as one another
    // Ensure sizes are the same
    cout << strlen(string1) << endl;
    cout << strlen(string2) << endl;
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    if (len1 != len2) return false;
    // Create table representing all letters
    int letters[26] = {0};
    // For first word, grab each letter, lowercase, add 1 to spot in table
    for (int i=0; i<len1; i++){
        int letter = string1[i];
        if (letter < 97){
            letter -= 65;
        } else{
            letter -= 97;
        }
        letters[letter]++;
    }
    // For second word, grab each letter, lowercase, subtract 1 to spot in table
    for (int i=0; i<len2; i++){
        int letter = string2[i];
        if (letter < 97){
            letter -= 65;
        } else {
            letter -= 97;
        }
        letters[letter]--;
    }
    // Go through list, if not equal to 0, return false
    for (int i=0; i<26; i++){
        if(letters[i] != 0) return false;
    }
    // Return True
    return true;
}


int main(int argc, char **argv){
    char string1[] = "corey";
    char string2[] = "ocrey";
    char string3[] = "coret";

    bool anagrams1 = anagrams(string1, string2);
    cout << anagrams1 << endl;
    bool anagrams2 = anagrams(string1, string3);
    cout << anagrams2 << endl;
    
    return 0;
}
